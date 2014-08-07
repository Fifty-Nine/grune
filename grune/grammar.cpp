#include "grune/grammar.hpp"

#include <sstream>

#include "grune/non_terminal.hpp"
#include "grune/production.hpp"

using namespace grune;

grammar::grammar(
    const sequence& non_terminals,
    const sequence& terminals,
    const production_list& productions,
    const symbol& start
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

bool grammar::operator==(const grammar& rhs) const
{
    return m_non_terminals == rhs.m_non_terminals && 
        m_terminals == rhs.m_terminals && 
        m_rules == rhs.m_rules && 
        m_start == rhs.m_start;
}

std::string grammar::to_string() const
{
    return grune::to_string(m_rules);
}

const symbol& grammar::start_symbol() const
{
    return m_start;
}

const production_list& grammar::productions() const
{
    return m_rules;
}

const sequence& grammar::non_terminals() const
{
    return m_non_terminals;
}

const sequence& grammar::terminals() const
{
    return m_terminals;
}

template<>
std::string grune::to_string<grammar>(const grammar& g)
{
    return g.to_string();
}
