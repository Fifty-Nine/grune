#ifndef GRUNE_SYMBOL_TRAITS_H
#define GRUNE_SYMBOL_TRAITS_H

#include <algorithm>
#include <boost/algorithm/string/join.hpp>
#include <list>
#include <string>

#include "grune/grune_fwd.hpp"

namespace grune
{

template<class T>
class symbol_traits;

template<class T>
bool is_terminal(const T& t)
{
    return symbol_traits<T>::is_terminal(t);
}

template<class T>
bool is_empty(const T& t)
{
    return symbol_traits<T>::is_empty(t);
}

template<class T>
std::string to_string(const T& t)
{
    return symbol_traits<T>::to_string(t);
}

template<class T>
std::string identifier(const T& t)
{
    return symbol_traits<T>::identifier(t);
}

template<class T>
std::string text(const T& t)
{
    return symbol_traits<T>::text(t);
}

template<class T>
struct symbol_traits;

template<class T>
struct default_symbol_traits
{
    static bool is_terminal(const T& t) { return t.is_terminal(); }
    static bool is_empty(const T& t) { return t.is_empty(); }
    static std::string to_string(const T& t) { return t.to_string(); }
    static std::string identifier(const T& t) { return t.identifier(); }
    static std::string text(const T& t) { return t.text(); }
};

template<class T>
struct basic_symbol_traits
{
    static bool is_terminal(const T& t) { return true; }
    static bool is_empty(const T& t) { return grune::text(t).empty(); }
    static std::string to_string(const T& t) { return "\"" + grune::text(t) + "\""; }
    static std::string identifier(const T& t) { return ""; }
};

template<class T>
struct numeric_symbol_traits : 
    public basic_symbol_traits<T>
{
    static bool is_empty(T) { return false; }
    static std::string text(T v) { return std::to_string(v); }
};

template<>
struct symbol_traits<std::string> : 
    public basic_symbol_traits<std::string>
{
    static bool is_empty(const std::string& s) { return s.empty(); }
    static std::string text(const std::string& s) { return s; }
};

template<>
struct symbol_traits<int> : 
    public numeric_symbol_traits<int>
{
};

template<>
std::string to_string<sequence>(const sequence& s);
template<>
std::string text<sequence>(const sequence& s);
template<>
bool is_terminal<sequence>(const sequence& s);

template<>
std::string to_string<sequence_list>(const sequence_list& s);
template<>
std::string to_string<production_list>(const production_list& p);

}

#endif /* GRUNE_SYMBOL_TRAITS_H */
