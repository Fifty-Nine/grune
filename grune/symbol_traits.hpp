#ifndef GRUNE_SYMBOL_TRAITS_H
#define GRUNE_SYMBOL_TRAITS_H

#include <algorithm>
#include <boost/algorithm/string/join.hpp>
#include <list>
#include <string>

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
struct symbol_traits
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
    static std::string text(const T& t) { return ""; }
};

template<class T>
struct numeric_symbol_traits : 
    public basic_symbol_traits<T>
{
    static bool is_empty(T) { return false; }
    static std::string text(T v) { return std::to_string(v); }
};

template<class List>
struct symbol_list_traits : public basic_symbol_traits<List>
{
    typedef typename List::value_type T;
    
    static std::string separator() { return ", "; }

    static bool is_terminal(const List& l) 
    { 
        return all_of(l.begin(), l.end(), grune::is_terminal<T>);
    }

    static bool is_empty(const List& l)
    {
        return all_of(l.begin(), l.end(), grune::is_empty<T>);
    }

    static std::string to_string(const List& l)
    {
        if (is_empty(l)) { return "\"\""; }

        std::vector<std::string> result(l.size());
        transform(l.begin(), l.end(), result.begin(), grune::to_string<T>);

        return boost::algorithm::join(result, 
            symbol_traits<List>::separator()); 
    }

    static std::string text(const List& l)
    {
        std::string result;
        for (auto elem : l)
        {
            if (!elem.is_terminal()) return "";
            result += grune::text(elem);
        }
        return result;
    }

};

template<template<class, class...> class List, class T, class... Rest>
struct symbol_traits<List<T, Rest...>> : 
    public symbol_list_traits<List<T, Rest...>>
{
    static std::string separator() { return ", "; }
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

}

#endif /* GRUNE_SYMBOL_TRAITS_H */
