#include "unit_tests/tests.hpp"
#include "grune/all.hpp"
#include "grune/grammars/tom_dick_and_harry.hpp"

using namespace grune;

class misc_tests : public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(misc_tests);
    CPPUNIT_TEST(test_is_terminal);
    CPPUNIT_TEST(test_is_empty);
    CPPUNIT_TEST(test_generate);
    CPPUNIT_TEST_SUITE_END();

public:
    void test_is_terminal()
    {
        symbol lit("l");
        symbol empty;
        non_terminal nt("nt");
        sequence nt_seq { lit, nt };
        sequence t_seq { lit, lit };
        sequence s { lit, lit };

        CPPUNIT_ASSERT(is_terminal(lit));
        CPPUNIT_ASSERT(is_terminal(empty));
        CPPUNIT_ASSERT(!is_terminal(nt)); 
        CPPUNIT_ASSERT(!is_terminal(nt_seq));
        CPPUNIT_ASSERT(is_terminal(t_seq));
        CPPUNIT_ASSERT(is_terminal(s));

        production ntp { nt, { nt_seq, t_seq } };
        production tp { nt, { t_seq } };

        CPPUNIT_ASSERT(!is_terminal(ntp));
        CPPUNIT_ASSERT(is_terminal(tp));
    }
    
    void test_is_empty()
    {
        symbol lit("l");
        symbol empty;
        non_terminal nt("nt");

        CPPUNIT_ASSERT(!is_empty(lit));
        CPPUNIT_ASSERT(is_empty(empty));
        CPPUNIT_ASSERT(!is_empty(nt));
    }

    void test_generate()
    {
        sequence_list result = generate(grammars::tom_dick_and_harry(), 5);

        CPPUNIT_ASSERT_EQUAL(result.size(), (sequence::size_type)5);

        sequence_list expected {
            { "tom" },
            { "dick" },
            { "harry" }, 
            { "tom", " and ", "tom" },
            { "tom", " and ", "dick" }
        };

        CPPUNIT_ASSERT_EQUAL(expected, result);

        non_terminal S("S");
        non_terminal A("A");
        non_terminal B("B");
        grammar finite
        {
            { S, A, B },
            { "0", "1" },
            {
                /* S -> AB */
                {
                    S, { { A, B } }
                },
                /* A -> 01 | 10 */
                {
                    A, { { "0", "1" }, { "1", "0" } }
                },
                /* B -> 11 | 00 */
                {
                    B, { { "1", "1" }, { "0", "0" } }
                }
            },
            S
        };

        sequence_list expected_finite 
        {
            { "0", "1", "1", "1" },
            { "0", "1", "0", "0" },
            { "1", "0", "1", "1" },
            { "1", "0", "0", "0" },
            { "0", "1", "1", "1" },
            { "1", "0", "1", "1" },
            { "0", "1", "0", "0" },
            { "1", "0", "0", "0" }
        };

        CPPUNIT_ASSERT_EQUAL(expected_finite, generate(finite));
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(misc_tests);
