#ifndef GRUNE_PRODUCTION_HPP
#define GRUNE_PRODUCTION_HPP

#include <list>
#include <string>

#include "grune/symbol.hpp"

namespace grune 
{

class non_terminal;

/*
 * Represents a production rule in a grammar. For simplicity's sake,
 * only one right-hand side is allowed. Use multiple production objects
 * to represent a production with multiple right-hand sides.
 */
class production
{
public:
    /* 
     * Create a null/empty production.
     */
    production();

    /* 
     * Construct a production from the given non-terminal to the given
     * sequence.
     */
    production(const non_terminal& from, const sequence& to);

    /* 
     * Construct a production from the given left-hand side to the given
     * right-hand side.
     */
    production(const sequence& from, const sequence& to);

    /*
     * Test whether this production is valid.
     */
    bool initialized() const;

    /*
     * Test whether this production is the same as another.
     */
    bool operator==(const production& rhs) const;

    /*
     * Convert this production to a human-readable string.
     */
    std::string to_string() const;

    /*
     * Test whether this production may only produce terminal 
     * right-hand sides.
     */
    bool is_terminal() const;

    /*
     * Get the left-hand side of the production.
     */
    sequence lhs() const;

    /*
     * Get the right-hand side of the production.
     */
    sequence rhs() const;

    /* 
     * Apply this production as many times as possible to the given
     * sequence, returning all the possible results.
     */
    sequence_list apply(const sequence& s) const;

private:
    sequence m_from;
    sequence m_to;
};

/*
 * A list of production rules.
 */
typedef std::list<production> production_list;

/* 
 * Apply the given production as many times as possible to the given
 * sequence, returning all the possible results. The production is
 * only applied once for each instance of the left-hand side in the
 * given sequence. For example the production rule A -> B applied
 * to the sequence 'AAA' will produce three sequences:
 *
 *   BAA
 *   ABA
 *   AAB
 *
 * Note that in each instance, the production is applied only once
 * but the positition at which it is applied varies.
 */
sequence_list apply(const production& p, const sequence& s);

/* 
 * Apply each production in the given list as many times as possible to the 
 * given sequence, returning all the possible results.
 */
sequence_list apply(const production_list& p, const sequence& s);

/*
 * Convert this production to a human-readable string.
 */
std::string to_string(const production& p);

/*
 * Test whether the given production is terminal.
 */
bool is_terminal(const production& p);

}

#endif /* GRUNE_PRODUCTION_HPP */
