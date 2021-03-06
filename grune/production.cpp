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
    const sequence& to) : 
    m_from { from }, m_to(to)
{
}

/*
 * Create a production from the given sequence to the given
 * set of symbols.
 */
production::production(
    const sequence& from, 
    const sequence& to) : 
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

bool production::operator==(const production& rhs) const
{
    return m_from == rhs.m_from && 
        m_to == rhs.m_to;
}

/*
 * Pretty print the production.
 */
std::string production::to_string() const
{
    std::ostringstream result;
    result << grune::to_string(m_from);
    result << " = ";
    result << grune::to_string(m_to);
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
    return grune::is_terminal(m_to);
}

sequence production::lhs() const
{
    return m_from;
}

sequence production::rhs() const
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

        sequence copy(s.begin(), it);

        copy.insert(copy.end(), m_to.begin(), m_to.end());
        copy.insert(copy.end(), next(it, m_from.size()), s.end());

        result.push_back(copy);
        
        ++it;
    }

    return result;
}

sequence_list grune::apply(const production& p, const sequence& s)
{
    return p.apply(s);
}

sequence_list grune::apply(const production_list& ps, const sequence& s)
{
    sequence_list result;
    for (auto p : ps)
    {
        auto tmp = apply(p, s);
        std::move(tmp.begin(), tmp.end(), std::back_inserter(result));
    }
    return result;
}

std::string grune::to_string(const production& p)
{
    return p.to_string();
}

bool grune::is_terminal(const production& p)
{
    return p.is_terminal();
}
