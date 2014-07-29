#include "grune/all.hpp"

#include <iostream>

void test_anbncn(std::ostream& out)
{
    using namespace grune;
    non_terminal S("S");
    non_terminal Q("Q");
    grammar g 
    {
        { S, Q },
        { "a", "b", "c" },
        {
            { S, { { "a", "b", "c" }, { "a", S, Q } } },
            { { "b", Q, "c" }, { { "b", "b", "c", "c" } } },
            { { "c", Q }, { { Q, "c" } } },
        },
        S
    };

    auto begin = sentence_iterator(g); 
    auto end = next(begin, 3);
    for (auto it = begin; it != end; ++it)
    {
        out << to_string(*it) << std::endl;
    }
}

