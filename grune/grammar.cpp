#include "grune/grammar.hpp"

#include <sstream>

#include "grune/non_terminal.hpp"
#include "grune/production.hpp"

using namespace grune;

grammar::grammar(
    const sequence& non_terminals,
    const sequence& terminals,
    const production_list& productions,
    const non_terminal& start
    ) : 
    m_non_terminals(non_terminals),
    m_terminals(terminals),
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

