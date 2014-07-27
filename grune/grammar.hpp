#ifndef GRUNE_GRAMMAR_H
#define GRUNE_GRAMMAR_H

#include <list>
#include <string>

#include "grune/grune_fwd.hpp"
#include "grune/symbol.hpp"

namespace grune
{

/* Represents a Type-0 (or higher) Chomsky grammar. */
class grammar
{
public:
    grammar(
        const sequence& non_terminals,
        const sequence& terminals,
        const production_list& productions,
        const symbol& start
    );
    grammar();
    ~grammar();
    
    std::string to_string() const;
    const symbol& start_symbol() const;
    const production_list& productions() const;

private:
    sequence m_non_terminals;
    sequence m_terminals;
    production_list m_rules;
    symbol m_start;
};

}

#endif /* GRUNE_GRAMMAR_H */
