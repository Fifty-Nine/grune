#include "grune/all.hpp"
#include "grune/grammars/anbncn.hpp"

#include <iostream>

void test_anbncn(std::ostream& out)
{
    using namespace grune;
    auto g = grammars::anbncn();
    auto begin = sentence_iterator(g);
    auto end = next(begin, 3);
    for (auto it = begin; it != end; ++it)
    {
        out << text(*it) << std::endl;
    }
}

