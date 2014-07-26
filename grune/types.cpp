#include "grune/types.hpp"

#include <boost/iterator/transform_iterator.hpp>
#include <boost/algorithm/string/join.hpp>
#include <functional>

#include "grune/production.hpp"
#include "grune/symbol.hpp"
#include "grune/terminal.hpp"

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
