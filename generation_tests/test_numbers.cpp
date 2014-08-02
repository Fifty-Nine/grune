#include "grune/all.hpp"

#include <sstream>

using namespace grune;

sequence digits(int low = 0, int high = 10)
{
    sequence result;
    for (int i = low; i < high; ++i)
    {
        result.push_back(i);
    }
    return result;
}

void test_numbers_simple(std::ostream& out)
{
    /*
     * digit -> "0" | nonzero
     * nonzero -> "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
     * number -> digit | nonzero digit | nonzero nonzero digit
     */

    non_terminal Digit("digit");
    non_terminal Nonzero("nonzero");
    non_terminal Number("number");

    grammar g
    {
        { Digit, Nonzero, Number },
        digits(0, 1),
        {
            { Digit, { { 0 } } },
            { Digit, { { Nonzero } } },
            { Nonzero, { { 1 } } },
            { Number, { { Digit } } },
            { Number, { { Nonzero, Digit } } },
            { Number, { { Nonzero, Nonzero, Digit } } },
        },
        Number
    };

    auto begin = sentence_iterator(g);
    auto end = std::next(begin, 20);
    for (auto it = begin; it != end; ++it)
    {
        out << text(*it) << std::endl;
    }
}

void test_numbers(std::ostream& out)
{
    /*
     * digit -> "0" | nonzero
     * nonzero -> "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
     * number -> digit | nonzero digit | nonzero nonzero digit
     */

    non_terminal Digit("digit");
    non_terminal Nonzero("nonzero");
    non_terminal Number("number");

    grammar g
    {
        { Digit, Nonzero, Number },
        digits(0, 10), 
        {
            { Digit, { { 0 } } },
            { Digit, { { Nonzero } } },
            { Nonzero, { { 1 } } },
            { Nonzero, { { 2 } } },
            { Nonzero, { { 3 } } },
            { Nonzero, { { 4 } } },
            { Nonzero, { { 5 } } },
            { Nonzero, { { 6 } } },
            { Nonzero, { { 7 } } },
            { Nonzero, { { 8 } } },
            { Nonzero, { { 9 } } },
            { Number, { { Digit } } },
            { Number, { { Nonzero, Digit } } },
            { Number, { { Nonzero, Nonzero, Digit } } }
        },
        Number
    };

    auto begin = sentence_iterator(g);
    auto end = std::next(begin, 20);
    for (auto it = begin; it != end; ++it)
    {
        out << text(*it) << std::endl;
    }
}

