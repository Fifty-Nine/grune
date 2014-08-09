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

/* 
 * Determine whether the given symbol is a terminal. 
 */
template<class T>
bool is_terminal(const T& t)
{
    return symbol_traits<T>::is_terminal(t);
}

/* 
 * Determine whether the given symbol is the empty symbol. 
 */
template<class T>
bool is_empty(const T& t)
{
    return symbol_traits<T>::is_empty(t);
}

/* 
 * Convert the given symbol to a string. 
 */
template<class T>
std::string to_string(const T& t)
{
    return symbol_traits<T>::to_string(t);
}

/* 
 * Get the identifier for the given non-terminal, or
 * if the symbol is terminal, return the empty string.
 */
template<class T>
std::string identifier(const T& t)
{
    return symbol_traits<T>::identifier(t);
}

/*
 * Get the literal text of the symbol. For terminals,
 * this is like to_string, but the result won't be
 * wrapped in quotes. For non-terminals, this just 
 * returns the identifier.
 */
template<class T>
std::string text(const T& t)
{
    return symbol_traits<T>::text(t);
}

/*
 * The symbol traits template. Specialize this template to create
 * symbols with your own classes.
 */
template<class T>
struct symbol_traits;

/*
 * Provides a default implementation of symbol_traits template that
 * assumes that all the required functions are implemented as members
 * of T. You can make use of this template via inheritance, e.g.:
 *
 * struct symbol_traits<MyClass> : 
 *   default_symbol_traits<MyClass>
 * { };
 *
 */
template<class T>
struct default_symbol_traits
{
    static bool is_terminal(const T& t) { return t.is_terminal(); }
    static bool is_empty(const T& t) { return t.is_empty(); }
    static std::string to_string(const T& t) { return t.to_string(); }
    static std::string identifier(const T& t) { return t.identifier(); }
    static std::string text(const T& t) { return t.text(); }
};

/* 
 * A basic symbol_traits implementation for literal terminals. If your
 * class should always be considered terminal, this is a good start. You
 * will need to provide your own text() function. 
 */
template<class T>
struct simple_terminal_traits
{
    static bool is_terminal(const T& t) { return true; }
    static bool is_empty(const T& t) { return grune::text(t).empty(); }
    static std::string to_string(const T& t) { return "\"" + grune::text(t) + "\""; }
    static std::string identifier(const T& t) { return ""; }
};

/* 
 * A symbol_traits implementation for numeric primitives.
 */
template<class T>
struct numeric_symbol_traits : 
    public simple_terminal_traits<T>
{
    static bool is_empty(T) { return false; }
    static std::string text(T v) { return std::to_string(v); }
};

/*
 * A symbol_traits specialization for strings. 
 */
template<>
struct symbol_traits<std::string> : 
    public simple_terminal_traits<std::string>
{
    static bool is_empty(const std::string& s) { return s.empty(); }
    static std::string text(const std::string& s) { return s; }
};

/*
 * A symbol_traits specialization for ints.
 */
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
