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
struct symbol_traits
{
    static bool is_terminal(const T& t) { return t.is_terminal(); }
    static bool is_empty(const T& t) { return t.is_empty(); }
    static std::string to_string(const T& t) { return t.to_string(); }
};

template<class List>
struct symbol_list_traits
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
};

template<template<class, class...> class List, class T, class... Rest>
struct symbol_traits<List<T, Rest...>> : 
    public symbol_list_traits<List<T, Rest...>>
{
    static std::string separator() { return ", "; }
};

}

#endif /* GRUNE_SYMBOL_TRAITS_H */
