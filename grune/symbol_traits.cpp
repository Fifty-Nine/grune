#include "grune/symbol_traits.hpp"

#include <flatten/flatten.hpp>
#include <map>
#include <iterator>
#include <sstream>

#include "grune/production.hpp"
#include "grune/symbol.hpp"

using namespace grune;

namespace
{

template<class List>
std::string list_to_string(const List& l, const std::string& separator)
{
    typedef typename List::value_type T;
    if (l.empty()) { return "\"\""; }

    std::vector<std::string> result(l.size());
    transform(l.begin(), l.end(), result.begin(), grune::to_string<T>);

    return boost::algorithm::join(result, separator);
}

}

template<>
std::string grune::to_string<sequence>(const sequence& s)
{
    return list_to_string(s, ", ");
}

template<>
bool grune::is_terminal<sequence>(const sequence& s)
{
    return all_of(s.begin(), s.end(), grune::is_terminal<symbol>);
}

template<>
std::string grune::text<sequence>(const sequence& s)
{
    std::string result;
    for (auto elem : s)
    {
        if (!elem.is_terminal()) return "";
        result += grune::text(elem);
    }
    return result;
}

template<>
std::string grune::to_string<sequence_list>(const sequence_list& s)
{
    return list_to_string(s, " | ");
}

template<>
std::string grune::to_string<production_list>(const production_list& ps)
{
    typedef std::multimap<sequence, sequence> Groups;
    Groups groups;

    for (auto it = ps.begin(); it != ps.end(); ++it)
    {
        groups.insert(make_pair(it->lhs(), it->rhs())); 
    }

    std::ostringstream out;
    for (auto p : ps)
    {
        sequence_list sequences;

        auto range = groups.equal_range(p.lhs());

        if (range.first == range.second) { continue; }

        flatten::flatten<sequence>(
            range.first, range.second, 
            std::back_inserter(sequences)
        );

        out << grune::to_string(p.lhs());
        out << " = ";
        out << grune::to_string(sequences);
        out << ";" << std::endl;

        groups.erase(range.first, range.second);
    }

    return out.str();
}


