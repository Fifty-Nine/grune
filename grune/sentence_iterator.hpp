#ifndef GRUNE_SENTENCE_ITERATOR
#define GRUNE_SENTENCE_ITERATOR

#include <boost/operators.hpp>

#include "grune/symbol.hpp"

namespace grune
{

class grammar;

/*
 * An iterator that allows iterating over all the possible sentences
 * in a grammar in breadth-first order.
 *
 * Note that the list may contain duplicates as the same sentence
 * may be produced in multiple ways.
 */
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
    /* 
     * Construct a null sentence_iterator. This represents the 
     * end of any sentence_iterator range.
     */
    sentence_iterator() : m_g(nullptr) { }

    /* 
     * Construct a sentence_iterator for the sentences in the
     * given grammar, positioned at the first sentence in the
     * grammar.
     */
    sentence_iterator(const grammar& g);

    /*
     * Test whether this sentence_iterator is the same as another.
     */
    bool operator==(const sentence_iterator& other) const;

    /*
     * Get the sentence pointed at by this sentence iterator.
     */
    const sequence& operator*() const;
    
    /*
     * Get the sentence pointed at by this sentence iterator.
     */
    const sequence* operator->() const;

    /*
     * Advance the iterator in-place.
     */
    sentence_iterator& operator++();

    /*
     * Advance the iterator, returning a copy of the current
     * value prior to being advanced.
     */
    sentence_iterator operator++(int);

private:
    bool at_end() const;

    const grammar* m_g;
    sequence m_current;
    std::list<sequence> m_q;
};

}

#endif /* GRUNE_SENTENCE_ITERATOR */
