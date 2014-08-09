#include "unit_tests/tests.hpp"
#include "grune/non_terminal.hpp"

using namespace grune;

GRUNE_TEST_SUITE(non_terminal_test)

GRUNE_TEST_CASE(non_terminal_tests, to_string_test)
{
    non_terminal nt("non_term");
    BOOST_CHECK_EQUAL(std::string("non_term"), nt.to_string());
}
GRUNE_TEST_CASE_END()

GRUNE_TEST_SUITE_END()
