#include "unit_tests/tests.hpp"
#include "grune/symbol.hpp"

using namespace grune;

GRUNE_TEST_SUITE(literal_tests)

GRUNE_TEST_CASE(literal_tests, to_string_test)
{
    symbol l("literal");
    BOOST_CHECK_EQUAL(std::string("\"literal\""), l.to_string());
}
GRUNE_TEST_CASE_END()

GRUNE_TEST_SUITE_END()
