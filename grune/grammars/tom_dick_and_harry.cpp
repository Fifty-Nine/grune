#include "grune/grammars/tom_dick_and_harry.hpp"

#include "grune/non_terminal.hpp"
#include "grune/production.hpp"

grune::grammar grune::grammars::tom_dick_and_harry()
{
    non_terminal N("N");
    non_terminal S("S");
    non_terminal L("L");
    return
    {
        /* non-terminals */ 
        { N, S, L }, 
        /* terminals */
        { "tom", "dick", "harry", "and", ", " },
        /* productions */
        {
            /* Name -> tom | dick | harry */
            {
                { N },
                {
                    { "tom", "dick", "harry" }
                }
            },
            /* Sentence -> Name | List and Name */
            {
                { S },
                {
                    { N },
                    { L, "and", N }
                }
            },
            /* List -> Name, List | Name */
            {
                { L },
                { 
                    { N, ", ", L },
                    { N }
                }
            }
        },
        /* start symbol */
        S
    };
}

