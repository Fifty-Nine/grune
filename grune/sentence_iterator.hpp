#ifndef GRUNE_SENTENCE_ITERATOR
#define GRUNE_SENTENCE_ITERATOR

#include <queue>

#include "grune/symbol.hpp"

namespace grune
{

class sentence_iterator : 
    public std::iterator<
        std::input_iterator_tag,
        sequence
    >
{
    void advance()
    {
        while (!m_q.empty())
        {
            sequence s = m_q.back();
            m_q.pop();

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
        for (auto p : m_g.productions())
        {
            enqueue(p.apply(s));
        }
    }

    void enqueue(const sequence_list& l)
    {
        for (auto s : l) { m_q.push(s); }
    }

public:
    sentence_iterator() = default;
    sentence_iterator(const grammar& g) : 
        m_g(g)
    {
        m_q.push({g.start_symbol()});
        advance();
    }

    bool operator==(const sentence_iterator& other)
    {
        return
            m_current == other.m_current &&
            m_q == other.m_q;
    }

    bool operator!=(const sentence_iterator& other)
    {
        return !(*this == other);
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
    grammar m_g;
    sequence m_current;
    std::queue<sequence> m_q;
};

}

#endif /* GRUNE_SENTENCE_ITERATOR */
