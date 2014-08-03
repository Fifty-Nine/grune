#include "unit_tests/tests.hpp"
#include "grune/non_terminal.hpp"

using namespace grune;

BOOST_AUTO_TEST_SUITE(non_terminal_test)

BOOST_AUTO_TEST_CASE(to_string_test)
{
    non_terminal nt("non_term");
    BOOST_CHECK_EQUAL(std::string("non_term"), nt.to_string());
}

BOOST_AUTO_TEST_SUITE_END()
