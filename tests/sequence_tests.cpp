#include "tests/tests.hpp"
#include "grune/non_terminal.hpp"
#include "grune/types.hpp"

using namespace grune;

class sequence_tests : public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(sequence_tests);
    CPPUNIT_TEST(test_to_string);
    CPPUNIT_TEST_SUITE_END();

public:
    void test_to_string()
    {
        non_terminal A("A");
        non_terminal B("B");
        symbol c("c");

        sequence s { A, B, c };

        std::string expected = "A, B, \"c\"";
        CPPUNIT_ASSERT_EQUAL(expected, to_string(s));

        expected = "\"\"";
        CPPUNIT_ASSERT_EQUAL(expected, to_string(sequence()));
    }
    
};

CPPUNIT_TEST_SUITE_REGISTRATION(sequence_tests);
