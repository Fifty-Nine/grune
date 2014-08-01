#ifndef GRUNE_SENTENCE_ITERATOR
#define GRUNE_SENTENCE_ITERATOR

#include <boost/operators.hpp>

#include "grune/symbol.hpp"

namespace grune
{

class grammar;

class sentence_iterator : 
    public std::iterator<
        std::input_iterator_tag,
        sequence
    >, 
    boost::equality_comparable<sentence_iterator>
{
    void advance();
    void apply_all_productions(const sequence& s);
    void enqueue(const sequence_list& l);

public:
    sentence_iterator() : m_g(nullptr) { }
    sentence_iterator(const grammar& g);

    bool operator==(const sentence_iterator& other) const;

    const sequence& operator*() const;
    const sequence* operator->() const;

    sentence_iterator& operator++();
    sentence_iterator operator++(int);

private:
    bool at_end() const;

    const grammar* m_g;
    sequence m_current;
    std::list<sequence> m_q;
};

}

#endif /* GRUNE_SENTENCE_ITERATOR */
