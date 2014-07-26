#include "tests/tests.hpp"
#include "grammar/all.hpp"

using namespace grammar;

class production_test : public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(production_test);
    CPPUNIT_TEST(test_initialized);
    CPPUNIT_TEST(test_to_string);
    CPPUNIT_TEST_SUITE_END();

public:
    void test_initialized()
    {
        non_terminal nt("S");
        production uninit;
        production init(&nt);

        CPPUNIT_ASSERT(!uninit.initialized());
        CPPUNIT_ASSERT(init.initialized());
    }
    
    void test_to_string()
    {
        non_terminal left("left");
        non_terminal right("right");
        literal l1("1");
        literal l2("2");

        production p(&left, {&right, &l1, &l2});

        std::string expected = "left = right, \"1\", \"2\"";
        CPPUNIT_ASSERT_EQUAL(expected, p.to_string());
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(production_test);
