#include "unit_tests/tests.hpp"
#include "grune/all.hpp"
#include "grune/grammars/tom_dick_and_harry.hpp"

using namespace grune;

BOOST_AUTO_TEST_SUITE(misc_tests)

BOOST_AUTO_TEST_CASE(is_terminal_test)
{
    symbol lit("l");
    symbol empty;
    non_terminal nt("nt");
    sequence nt_seq { lit, nt };
    sequence t_seq { lit, lit };
    sequence s { lit, lit };

    BOOST_CHECK(is_terminal(lit));
    BOOST_CHECK(is_terminal(empty));
    BOOST_CHECK(!is_terminal(nt)); 
    BOOST_CHECK(!is_terminal(nt_seq));
    BOOST_CHECK(is_terminal(t_seq));
    BOOST_CHECK(is_terminal(s));

    production ntp0 { nt, { nt_seq } };
    production ntp1 { nt, { t_seq } };
    production tp { nt, { t_seq } };

    BOOST_CHECK(!is_terminal(ntp0));
    BOOST_CHECK(is_terminal(ntp1));
    BOOST_CHECK(is_terminal(tp));
}

BOOST_AUTO_TEST_CASE(is_empty_test)
{
    symbol lit("l");
    symbol empty;
    non_terminal nt("nt");

    BOOST_CHECK(!is_empty(lit));
    BOOST_CHECK(is_empty(empty));
    BOOST_CHECK(!is_empty(nt));
}

BOOST_AUTO_TEST_CASE(generate_test)
{
    sequence_list result = generate(grammars::tom_dick_and_harry(), 5);

    BOOST_CHECK_EQUAL(result.size(), (sequence::size_type)5);

    sequence_list expected {
        { "tom" },
        { "dick" },
        { "harry" }, 
        { "tom", " and ", "tom" },
        { "tom", " and ", "dick" }
    };

    BOOST_CHECK_EQUAL(expected, result);

    non_terminal S("S");
    non_terminal A("A");
    non_terminal B("B");
    grammar finite
    {
        { S, A, B },
        { 0, 1 },
        {
            /* S -> AB */
            { S, { A, B } },
            /* A -> 01 | 10 */
            { A, { 0, 1 } },
            { A, { 1, 0 } },
            /* B -> 11 | 00 */
            { B, { 1, 1 } },
            { B, { 0, 0 } }
        },
        S
    };

    sequence_list expected_finite 
    {
        { 0, 1, 1, 1 },
        { 0, 1, 0, 0 },
        { 1, 0, 1, 1 },
        { 1, 0, 0, 0 },
        { 0, 1, 1, 1 },
        { 1, 0, 1, 1 },
        { 0, 1, 0, 0 },
        { 1, 0, 0, 0 }
    };

    BOOST_CHECK_EQUAL(expected_finite, generate(finite));
}

BOOST_AUTO_TEST_SUITE_END()
