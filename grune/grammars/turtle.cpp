#include "grune/grammars/turtle.hpp"

#include "grune/non_terminal.hpp"
#include "grune/production.hpp"

grune::grammar grune::grammars::cyclic_manhattan_turtle()
{
    non_terminal M("M");
    return
    {
        /* non-terminals */ 
        { M }, 
        /* terminals */
        { "n", "s", "e", "w" },
        /* productions */
        {
            /* M -> nMs | eMw | {} */
            { M, { "n", M, "s" } }, 
            { M, { "e", M, "w" } }, 
            { M, { } }, 
            /* ne -> en */
            { { "n", "e" }, { "e", "n" } },
            /* ns -> sn */
            { { "n", "s" }, { "s", "n" } },
            /* nw -> wn */
            { { "n", "w" }, { "w", "n" } },
            /* ne -> en */
            { { "e", "n" }, { "n", "e" } },
            /* es -> se */
            { { "e", "s" }, { "s", "e" } },
            /* ew -> we */
            { { "e", "w" }, { "w", "e" } },
            /* sn -> ns */
            { { "s", "n" }, { "n", "s" } },
            /* se -> es */
            { { "s", "e" }, { "e", "s" } },
            /* sw -> ws */
            { { "s", "w" }, { "w", "s" } },
            /* wn -> nw */
            { { "w", "n" }, { "n", "w" } },
            /* we -> ew */
            { { "w", "e" }, { "e", "w" } },
            /* ws -> sw */
            { { "w", "s" }, { "s", "w" } },
        },
        /* start symbol */
        M
    };
}
