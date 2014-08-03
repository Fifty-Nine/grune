#include "grune/grammars/anbncn.hpp"

#include "grune/non_terminal.hpp"
#include "grune/production.hpp"

grune::grammar grune::grammars::anbncn()
{
    non_terminal S("S");
    non_terminal Q("Q");

    return
    {
        { S, Q }, /* non-terminals */
        { "a", "b", "c" }, /* terminals */
        {
            /* S -> abc | aSQ */
            { S, { "a", "b", "c" } },
            { S, { "a", S, Q } },
            /* bQc -> bbcc */
            { { "b", Q, "c" }, { "b", "b", "c", "c" } },
            /* cQ -> Qc */
            { { "c", Q }, { Q, "c" } },
        },
        S /* start */
    };
}
