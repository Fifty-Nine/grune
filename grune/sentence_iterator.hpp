#ifndef GRUNE_SENTENCE_ITERATOR
#define GRUNE_SENTENCE_ITERATOR

#include <boost/operators.hpp>
#include <queue>

#include "grune/grammar.hpp"
#include "grune/production.hpp"
#include "grune/symbol.hpp"

namespace grune
{

class sentence_iterator : 
    public std::iterator<
        std::input_iterator_tag,
        sequence
    >, 
    boost::equality_comparable<sentence_iterator>
{
    void advance()
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

    void apply_all_productions(const sequence& s)
    {
        for (auto p : m_g->productions())
        {
            enqueue(p.apply(s));
        }
    }

    void enqueue(const sequence_list& l)
    {
        for (auto s : l) { m_q.push_back(s); }
    }

public:
    sentence_iterator() : m_g(nullptr) { }
    sentence_iterator(const grammar& g) : 
        m_g(&g)
    {
        m_q.push_back({g.start_symbol()});
        advance();
    }

    bool operator==(const sentence_iterator& other) const
    {
        return (at_end() && other.at_end()) ||
            (m_g == other.m_g &&
             m_current == other.m_current &&
             m_q == other.m_q);
    }

    const sequence& operator*() const
    {
        return m_current;
    }

    const sequence* operator->() const
    {
        return &m_current;
    }

    sentence_iterator& operator++() 
    {
        advance();
        return *this;
    }

    sentence_iterator operator++(int) 
    {
        sentence_iterator result = *this;
        advance();
        return result;
    }

private:
    bool at_end() const
    {
        return m_current.empty() && m_q.empty();
    }

    const grammar* m_g;
    sequence m_current;
    std::list<sequence> m_q;
};

}

#endif /* GRUNE_SENTENCE_ITERATOR */
