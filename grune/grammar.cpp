#include "grune/grammar.hpp"

#include <sstream>

#include "grune/production.hpp"
#include "grune/types.hpp"

using namespace grune;

grammar::grammar(
    const std::list<non_terminal_ptr>& non_terminals,
    const std::list<terminal_ptr>& terminals,
    const std::list<production_ptr>& productions,
    non_terminal *start
    ) : 
    m_nonterm(non_terminals), 
    m_term(terminals),
    m_rules(productions),
    m_start(start)
{
}

grammar::grammar()
{
}

grammar::~grammar()
{
}

std::string grammar::to_string() const
{
    std::ostringstream result;

    for (auto p : m_rules)
    {
        result << grune::to_string(*p);
        result << ";\n";
    }

    return result.str();
}

