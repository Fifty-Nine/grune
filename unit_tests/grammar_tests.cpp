#include "unit_tests/tests.hpp"
#include "grune/all.hpp"

using namespace grune;

grammar test_grammar() 
{
    non_terminal A("A");
    non_terminal B("B");
    non_terminal C("C");

    symbol a("a");
    symbol b("b");
    symbol c("c");


    return grammar(
        { A, B, C },
        { a, b, c },
        {
            { A, { a, B } },        
            { B, { b, C } },
            { C, { c } },
            { C, { } },
        },
        A
    );
}

GRUNE_TEST_SUITE(grammar_tests)

GRUNE_TEST_CASE(grammar_tests, to_string_test)
{
    std::string expected = 
        "A = \"a\", B;\n"
        "B = \"b\", C;\n"
        "C = \"c\" | \"\";\n";
    BOOST_CHECK_EQUAL(expected, test_grammar().to_string());
}
GRUNE_TEST_CASE_END()

GRUNE_TEST_CASE(grammar_tests, generate_test)
{
    grammar g = test_grammar();

    const sentence_iterator begin(g);
    const sentence_iterator end;
    auto it = begin;

    sequence first = { "a", "b", "c" };
    sequence second = { "a", "b" };

    BOOST_CHECK_EQUAL(first, *it);
    BOOST_CHECK_EQUAL(first, *it++);
    BOOST_CHECK_EQUAL(second, *it);
    BOOST_CHECK_EQUAL(end, ++it); 

    sequence_list expected 
    {
        { "a", "b", "c" },
        { "a", "b" }
    };

    sequence_list actual(begin, end);
    BOOST_CHECK_EQUAL(expected, actual);
}
GRUNE_TEST_CASE_END()

GRUNE_TEST_SUITE_END()
