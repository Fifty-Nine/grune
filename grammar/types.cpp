#include "grammar/types.hpp"

#include <boost/iterator/transform_iterator.hpp>
#include <boost/algorithm/string/join.hpp>
#include <functional>

#include "grammar/production.hpp"
#include "grammar/symbol.hpp"
#include "grammar/terminal.hpp"

template<class T>
std::string list_to_string(const std::list<T*>& l, const std::string& sep)
{
    typedef std::function<std::string(T*)> Converter;
    typedef boost::transform_iterator<Converter, decltype(l.begin())> It;

    Converter cvt = [](T* v) { return to_string(*v); };
    auto range = std::make_pair(
        It(l.begin(), cvt), 
        It(l.end(), cvt)
    );

    return boost::algorithm::join(range, sep);
}

std::string grammar::to_string(const sequence& s)
{
    return list_to_string(s, ", ");
}

std::string grammar::to_string(const sentence& s)
{
    return list_to_string(s, ", ");
}

std::string grammar::to_string(const symbol& s)
{
    return s.to_string();
}

std::string grammar::to_string(const production& p)
{
    return p.to_string();
}

bool grammar::is_terminal(const sequence& s)
{
    return all_of(
        s.begin(), s.end(), 
        [](symbol* sym) { return is_terminal(*sym); }
    );
}

bool grammar::is_terminal(const sentence& s)
{
    return true;
}

bool grammar::is_terminal(const symbol& s)
{
    return s.is_terminal();
}

