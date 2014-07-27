#include "grune/all.hpp"

using namespace grune;

void test_turtle(std::ostream& out)
{
    non_terminal Move("Move");
    grammar g
    {
        { Move }, 
        { "north", "south", "east", "west" },
        {
            { Move,
                {
                    { "north", Move, "south" }, 
                    { "east", Move, "west" }, 
                    { }
                }
            },
            { { "north", "east" }, { { "east", "north" } } },
            { { "north", "south" }, { { "south", "north" } } },
            { { "north", "west" }, { { "west", "north" } } },
            { { "east", "north" }, { { "north", "east" } } },
            { { "east", "south" }, { { "south", "east" } } },
            { { "east", "west" }, { { "west", "east" } } },
            { { "south", "north" }, { { "north", "south" } } },
            { { "south", "east" }, { { "east", "south" } } },
            { { "south", "west" }, { { "west", "south" } } },
            { { "west", "north" }, { { "north", "west" } } },
            { { "west", "east" }, { { "east", "west" } } },
            { { "west", "south" }, { { "south", "west" } } },
        },
        Move
    };

    sentence_iterator begin(g);

    /* An infinite language, so just take 20 sentences. */
    sentence_iterator end = next(begin, 20);

    for (auto it = begin; it != end; ++it)
    {
        out << to_string(*it) << std::endl;
    }
}
