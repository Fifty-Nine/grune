#include "unit_tests/tests.hpp"
#include "grune/symbol.hpp"

using namespace grune;

class literal_tests : public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(literal_tests);
    CPPUNIT_TEST(test_to_string);
    CPPUNIT_TEST_SUITE_END();

public:
    void test_to_string()
    {
        symbol l("literal");
        CPPUNIT_ASSERT_EQUAL(std::string("\"literal\""), l.to_string());
    }
    
};

CPPUNIT_TEST_SUITE_REGISTRATION(literal_tests);
