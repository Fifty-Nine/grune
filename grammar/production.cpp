#include "grammar/production.hpp"

namespace grammar
{

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

}
