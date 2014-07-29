#include "grune/all.hpp"

#include "grune/grammars/turtle.hpp"

using namespace grune;

void test_turtle(std::ostream& out)
{
    auto g = grammars::cyclic_manhattan_turtle();
    sentence_iterator begin(g);

    /* An infinite language, so just take 20 sentences. */
    sentence_iterator end = next(begin, 20);

    for (auto it = begin; it != end; ++it)
    {
        out << to_string(*it) << std::endl;
    }
}
