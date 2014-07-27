#include "grune/production.hpp"

#include <algorithm>
#include <sstream>

#include "grune/non_terminal.hpp"
#include "grune/types.hpp"

using namespace grune;

/*
 * Create a null production.
 */
production::production() :
    m_from(), m_to()
{
}

/*
 * Create a production from the given nonterminal to the given
 * set of symbols.
 */
production::production(
    non_terminal *from, 
    const sequence_list& to) : 
    m_from { from }, m_to(to)
{
}

/*
 * Create a production from the given sequence to the given
 * set of symbols.
 */
production::production(
    const sequence& from, 
    const sequence_list& to) : 
    m_from(from), m_to(to)
{
}

/*
 * Test whether the production is initialized.
 */
bool production::initialized() const 
{
    return !m_from.empty();
}

/*
 * Pretty print the production.
 */
std::string production::to_string() const
{
    std::ostringstream result;
    result << grune::to_string(m_from);
    result << " = ";

    auto it = m_to.begin();

    while (true)
    {
        result << grune::to_string(*it);
        if (++it == m_to.end()) break;
        result << " | ";
    }

    return result.str();
}

/*
 * Test whether the right-hand side of this production is always a sentence.
 * Note that even if this is true, applying this production to a sequence
 * may result in a sequence with non-terminals, since the whole input will
 * probably not be replaced.
 */
bool production::is_terminal() const
{
    return all_of(
        m_to.begin(), m_to.end(), 
        [](const sequence& s) { return grune::is_terminal(s); }
    );
}

