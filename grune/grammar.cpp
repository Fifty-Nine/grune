#include "grune/grammar.hpp"

#include <sstream>

#include "grune/non_terminal.hpp"
#include "grune/production.hpp"
#include "grune/terminal.hpp"

using namespace grune;

grammar::grammar(
    const std::list<non_terminal>& non_terminals,
    const std::list<terminal>& terminals,
    const std::list<production>& productions,
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
        result << grune::to_string(p);
        result << ";\n";
    }

    return result.str();
}

