#include "grune/production.hpp"

#include <algorithm>
#include <boost/algorithm/string/replace.hpp>
#include <sstream>

#include "grune/non_terminal.hpp"

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
    const non_terminal& from, 
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

sequence production::lhs() const
{
    return m_from;
}

sequence_list production::rhs() const
{
    return m_to;
}

sequence_list production::apply(const sequence& s) const
{
    auto it = s.begin();
    sequence_list result;

    while (it != s.end())
    {
        it = search(it, s.end(), m_from.begin(), m_from.end());
        if (it == s.end())
        {
            break;
        }

        for (auto replace : m_to)
        {
            sequence copy(s.begin(), it);

            copy.insert(copy.end(), replace.begin(), replace.end());
            copy.insert(copy.end(), next(it, m_from.size()), s.end());

            result.push_back(copy);
        }
        ++it;
    }

    return result;
}
