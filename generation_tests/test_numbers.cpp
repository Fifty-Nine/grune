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

sequence_list to_seq_list(const sequence& s)
{
    sequence_list result;
    for (auto sym : s)
    {
        result.emplace_back( sequence { sym } );
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
            { Digit,   
                { 
                    { 0 },
                    { Nonzero }                
                }
            },
            { Nonzero, 
                { 
                    to_seq_list(digits(1, 2))
                } 
            },
            { Number,  
                { 
                    { Digit }, 
                    { Nonzero, Digit },
                    { Nonzero, Nonzero, Digit }
                }
            }
        },
        Number
    };

    auto begin = sentence_iterator(g);
    auto end = std::next(begin, 20);
    for (auto it = begin; it != end; ++it)
    {
        out << to_string(*it) << std::endl;
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
            { Digit,   
                { 
                    { 0 },
                    { Nonzero }                
                }
            },
            { Nonzero, 
                { 
                    to_seq_list(digits(1, 10))
                } 
            },
            { Number,  
                { 
                    { Digit }, 
                    { Nonzero, Digit },
                    { Nonzero, Nonzero, Digit }
                }
            }
        },
        Number
    };

    auto begin = sentence_iterator(g);
    auto end = std::next(begin, 20);
    for (auto it = begin; it != end; ++it)
    {
        out << to_string(*it) << std::endl;
    }
}

