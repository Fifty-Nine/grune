#include "grune/all.hpp"

#include <boost/filesystem.hpp>
#include <fstream>
#include <sstream>

using namespace grune;

namespace grune
{
    template<>
    struct symbol_traits<int> 
    {
        static std::string to_string(int i) 
        {
            std::ostringstream o;
            o << "\"" << i << "\"";
            return o.str();
        }

        static bool is_terminal(int) { return true; }
        static bool is_empty(int) { return false; }
    };
}

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

    for (auto it = sentence_iterator(g); it != sentence_iterator(); ++it)
    {
        out << to_string(*it) << std::endl;
    }
}

typedef void (*test_fcn_t)(std::ostream&);
void run_test(test_fcn_t test, const std::string& name)
{
    std::ofstream results("./results/" + name + ".results");
    test(results);
}

#define RUN_TEST(name) run_test(name, #name)

int main()
{
    boost::filesystem::remove_all("./results");
    boost::filesystem::create_directories("./results");
    RUN_TEST(test_numbers);
    return 0;
}

