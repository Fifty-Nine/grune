#include "grune/grammars/tom_dick_and_harry.hpp"

#include "grune/non_terminal.hpp"
#include "grune/production.hpp"

grune::grammar grune::grammars::tom_dick_and_harry()
{
    non_terminal S("S");
    non_terminal L("L");
    non_terminal LT("N");

    return
    {
        /* non-terminals */ 
        { S, L, LT }, 
        /* terminals */
        { "tom", "dick", "harry", " and ", ", " },
        /* productions */
        {
            /* Sentence -> tom | dick | harry | List */ 
            {
                { S },
                {
                    { "tom" }, 
                    { "dick" }, 
                    { "harry" }, 
                    { L }
                }
            },
            /* List -> tom ListTail | dick ListTail | harry ListTail */
            {
                { L },
                {
                    { "tom", LT },
                    { "dick", LT },
                    { "harry", LT },
                }
            },
            /* ListTail -> , List | and "tom" | and "dick" | and "harry" */
            {
                { LT },
                { 
                    { ", ", L },
                    { " and ", "tom" },
                    { " and ", "dick" },
                    { " and ", "harry" },
                }
            }
        },
        /* start symbol */
        S
    };
}

