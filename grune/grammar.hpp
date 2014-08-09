#ifndef GRUNE_GRAMMAR_H
#define GRUNE_GRAMMAR_H

#include <list>
#include <string>

#include "grune/production.hpp"
#include "grune/symbol.hpp"

namespace grune
{

/* 
 * Represents a Type-0 (or higher) Chomsky grammar. 
 */
class grammar
{
public:
    /*
     * Construct a grammar with the given non-terminal symbols, 
     * the given terminal-symbols, the given list of production rules, 
     * and the given start symbol.
     */
    grammar(
        const sequence& non_terminals,
        const sequence& terminals,
        const production_list& productions,
        const symbol& start
    );

    /* 
     * Construct a null/empty grammar.
     */
    grammar();

    /*
     * Test whether this grammar is equivalent to another.
     */
    bool operator==(const grammar& rhs) const;    

    /*
     * Convert this grammar to a human-readable string representation.
     */
    std::string to_string() const;

    /* 
     * Get the list of non-terminals in this grammar.
     */
    const sequence& non_terminals() const;

    /* 
     * Get the list of terminals in this grammar.
     */
    const sequence& terminals() const;

    /*
     * Get the list of production rules in this grammar.
     */
    const production_list& productions() const;

    /*
     * Get the start symbol of this grammar.
     */
    const symbol& start_symbol() const;

private:
    sequence m_non_terminals;
    sequence m_terminals;
    production_list m_rules;
    symbol m_start;
};

/*
 * Convert the given grammar to a human-readable string representation.
 */
std::string to_string(const grammar& g); 

}

#endif /* GRUNE_GRAMMAR_H */
