#include <algorithm>
#include <iostream>

#include "grune/all.hpp"
#include "grune/grammars/tom_dick_and_harry.hpp"

using namespace grune;

void test_tdh(std::ostream& o)
{
    auto g = grune::grammars::tom_dick_and_harry();

    auto begin = sentence_iterator(g);
    auto end = next(begin, 18);
    for (auto it = begin; it != end; ++it)
    {
        o << text(*it) << std::endl;
    }
}

