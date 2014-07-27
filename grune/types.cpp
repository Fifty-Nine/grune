#include "grune/types.hpp"

#include <boost/algorithm/string/join.hpp>
#include <functional>

#include "grune/production.hpp"
#include "grune/symbol.hpp"
#include "grune/terminal.hpp"

template<class T>
std::string list_to_string(const std::list<T*>& l, const std::string& sep)
{
    if (l.empty())
    {
        /* An empty list is the same as the empty literal. */
        return "\"\"";
    }

    std::list<std::string> elems;
    for (auto s : l)
    {
        if (!is_empty(*s))
        {
            elems.push_back(s->to_string());
        }
    }

    return boost::algorithm::join(elems, sep);
}

std::string grune::to_string(const sequence& s)
{
    return list_to_string(s, ", ");
}

std::string grune::to_string(const sentence& s)
{
    return list_to_string(s, ", ");
}

std::string grune::to_string(const symbol& s)
{
    return s.to_string();
}

std::string grune::to_string(const production& p)
{
    return p.to_string();
}

bool grune::is_terminal(const sequence& s)
{
    return all_of(
        s.begin(), s.end(), 
        [](symbol* sym) { return is_terminal(*sym); }
    );
}

bool grune::is_terminal(const sentence& s)
{
    return true;
}

bool grune::is_terminal(const symbol& s)
{
    return s.is_terminal();
}

bool grune::is_terminal(const production& p)
{
    return p.is_terminal();
}

bool grune::is_empty(const symbol& s)
{
    return s.is_empty();
}
