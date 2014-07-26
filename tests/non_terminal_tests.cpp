#include "tests/tests.hpp"
#include "grammar/non_terminal.hpp"

using namespace grammar;

class non_terminal_tests : public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(non_terminal_tests);
    CPPUNIT_TEST(test_to_string);
    CPPUNIT_TEST_SUITE_END();

public:
    void test_to_string()
    {
        non_terminal nt("non_term");
        CPPUNIT_ASSERT_EQUAL(std::string("non_term"), nt.to_string());
    }
    
};

CPPUNIT_TEST_SUITE_REGISTRATION(non_terminal_tests);
