#ifndef GRUNE_GRAMMAR_H
#define GRUNE_GRAMMAR_H

#include <list>
#include <string>

#include "grune/grune_fwd.hpp"

namespace grune
{

/* Represents a Type-0 (or higher) Chomsky grammar. */
class grammar
{
public:
    grammar(
        const std::list<non_terminal>& non_terminals,
        const std::list<terminal>& terminals,
        const std::list<production>& productions,
        non_terminal *start
    );
    grammar();
    ~grammar();
    
    std::string to_string() const;

private:
    std::list<non_terminal> m_nonterm;
    std::list<terminal> m_term;
    std::list<production> m_rules;
    non_terminal *m_start;
};

}

#endif /* GRUNE_GRAMMAR_H */
