#include "unit_tests/tests.hpp"
#include "grune/non_terminal.hpp"

using namespace grune;

GRUNE_TEST_SUITE(sequence_tests)

GRUNE_TEST_CASE(sequence_tests, test_to_string)
{
    non_terminal A("A");
    non_terminal B("B");
    symbol c("c");

    sequence s { A, B, c };

    std::string expected = "A, B, \"c\"";
    BOOST_CHECK_EQUAL(expected, to_string(s));

    expected = "\"\"";
    BOOST_CHECK_EQUAL(expected, to_string(sequence()));

    sequence_list sl { s, { A, c, B } };
    expected = "A, B, \"c\" | A, \"c\", B";
    BOOST_CHECK_EQUAL(expected, to_string(sl));

    expected = "\"\"";
    BOOST_CHECK_EQUAL(expected, to_string(sequence_list()));
}
GRUNE_TEST_CASE_END()

GRUNE_TEST_SUITE_END()
