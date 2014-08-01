#include "grune/sentence_iterator.hpp"

#include "grune/grammar.hpp"
#include "grune/production.hpp"
#include "grune/symbol.hpp"

using namespace grune;

void sentence_iterator::advance()
{
    while (!m_q.empty())
    {
        sequence s = m_q.front();
        m_q.pop_front();

        if (is_terminal(s))
        {
            m_current = s;
            return;
        }

        apply_all_productions(s);
    }
    m_current = sequence();
}

void sentence_iterator::apply_all_productions(const sequence& s)
{
    for (auto p : m_g->productions())
    {
        enqueue(p.apply(s));
    }
}

void sentence_iterator::enqueue(const sequence_list& l)
{
    for (auto s : l) { m_q.push_back(s); }
}

sentence_iterator::sentence_iterator(const grammar& g) : 
    m_g(&g)
{
    m_q.push_back({g.start_symbol()});
    advance();
}

bool sentence_iterator::operator==(const sentence_iterator& other) const
{
    return (at_end() && other.at_end()) ||
        (m_g == other.m_g &&
         m_current == other.m_current &&
         m_q == other.m_q);
}

const sequence& sentence_iterator::operator*() const
{
    return m_current;
}

const sequence* sentence_iterator::operator->() const
{
    return &m_current;
}

sentence_iterator& sentence_iterator::operator++() 
{
    advance();
    return *this;
}

sentence_iterator sentence_iterator::operator++(int) 
{
    sentence_iterator result = *this;
    advance();
    return result;
}

bool sentence_iterator::at_end() const
{
    return m_current.empty() && m_q.empty();
}
