#ifndef GRUNE_NON_TERMINAL_HPP
#define GRUNE_NON_TERMINAL_HPP

#include "grune/grune_fwd.hpp"
#include "grune/symbol.hpp"

namespace grune 
{

class symbol;

class non_terminal : 
    boost::less_than_comparable<non_terminal>,
    boost::equality_comparable<non_terminal>
{
public:
    non_terminal(const std::string& identifier = "");

    std::string identifier() const;
    std::string text() const;
    std::string to_string() const;
    bool is_terminal() const { return false; }
    bool is_empty() const { return false; }

    bool operator==(const non_terminal& other) const
    {
        return m_identifier == other.m_identifier;
    }

    bool operator<(const non_terminal& other) const
    {
        return m_identifier < other.m_identifier;
    }

private:
    std::string m_identifier;
};

template<>
struct symbol_traits<non_terminal> : 
    default_symbol_traits<non_terminal> 
{ };

} 

#endif /* GRUNE_NON_TERMINAL_HPP */
