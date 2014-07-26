#include "grammar/production.hpp"

#include <sstream>

#include "grammar/non_terminal.hpp"

using namespace grammar;

/*
 * Create a null production.
 */
production::production() :
    m_from(nullptr), m_to()
{
}

/*
 * Create a production from the given nonterminal to the given
 * set of symbols.
 */
production::production(
    non_terminal *from, 
    std::initializer_list<symbol*> to) : 
    m_from(from), m_to(to)
{
}

/*
 * Test whether the production is initialized.
 */
bool production::initialized() const 
{
    return m_from != nullptr;
}

/*
 * Pretty print the production.
 */
std::string production::to_string() const
{
    std::ostringstream result;
    result << m_from->to_string();
    result << " = ";

    auto it = m_to.begin();

    while (true)
    {
        result << (*it)->to_string();
        if (++it == m_to.end()) break;
        result << ", ";
    }

    return result.str();
}

