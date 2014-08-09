#ifndef GRUNE_NON_TERMINAL_HPP
#define GRUNE_NON_TERMINAL_HPP

#include "grune/grune_fwd.hpp"
#include "grune/symbol.hpp"

namespace grune 
{

class symbol;

/*
 * Represents a non-terminal symbol in a grammar.
 */
class non_terminal : 
    boost::less_than_comparable<non_terminal>,
    boost::equality_comparable<non_terminal>
{
public:
    /* 
     * Construct a non-terminal with the given identifier.
     */
    non_terminal(const std::string& identifier = "");

    /*
     * Get this non-terminal's identifier.
     */
    std::string identifier() const;

    /*
     * Get the text of this non-terminal (same as identifier())
     */
    std::string text() const;

    /*
     * Convert this non-terminal to a human-readable string.
     */
    std::string to_string() const;

    /*
     * Override of is_terminal for non-terminals.
     * Always returns false.
     */
    bool is_terminal() const { return false; }

    /*
     * Override of is_empty for non-terminals.
     * Always returns false since non-terminals never represent
     * the empty string.
     */
    bool is_empty() const { return false; }

    /*
     * Test whether this non-terminal is the same as another.
     */
    bool operator==(const non_terminal& other) const
    {
        return m_identifier == other.m_identifier;
    }

    /*
     * Order this non-terminal. Returns true if this non-terminal
     * should come before the given non-terminal in an ordering.
     */
    bool operator<(const non_terminal& other) const
    {
        return m_identifier < other.m_identifier;
    }

private:
    std::string m_identifier;
};

/*
 * A specialization of symbol_traits for non-terminals.
 */
template<>
struct symbol_traits<non_terminal> : 
    default_symbol_traits<non_terminal> 
{ };

} 

#endif /* GRUNE_NON_TERMINAL_HPP */
