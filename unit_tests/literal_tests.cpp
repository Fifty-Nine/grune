#include "unit_tests/tests.hpp"
#include "grune/symbol.hpp"

using namespace grune;

BOOST_AUTO_TEST_SUITE(literal_tests)

BOOST_AUTO_TEST_CASE(to_string_test)
{
    symbol l("literal");
    BOOST_CHECK_EQUAL(std::string("\"literal\""), l.to_string());
}

BOOST_AUTO_TEST_SUITE_END()
