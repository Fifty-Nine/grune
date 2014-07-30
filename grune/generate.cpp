#include "grune/generate.hpp"

#include "grune/sentence_iterator.hpp"

grune::sequence_list grune::generate(const grammar& g, int count)
{
    auto begin = sentence_iterator(g);
    auto end = count >= 0 ? next(begin, count) : sentence_iterator();

    return sequence_list(begin, end);
}

