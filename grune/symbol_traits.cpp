#include "grune/symbol_traits.hpp"

#include <flatten/flatten.hpp>
#include <map>
#include <iterator>
#include <sstream>

#include "grune/production.hpp"
#include "grune/symbol.hpp"

using namespace grune;

bool symbol_traits<production_list>::is_terminal(const production_list& p)
{
    return all_of(p.begin(), p.end(), &grune::is_terminal<production>);
}

bool symbol_traits<production_list>::is_empty(const production_list& p)
{
    return p.empty();
}

std::string symbol_traits<production_list>::to_string(const production_list& ps)
{
    typedef std::multimap<sequence, sequence> Groups;
    Groups groups;

    for (auto it = ps.begin(); it != ps.end(); ++it)
    {
        auto rhs = it->rhs();
        groups.insert(make_pair(it->lhs(), rhs.empty() ? sequence() : rhs.front()));
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


