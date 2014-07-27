#include "tests/tests.hpp"
#include "grune/all.hpp"

using namespace grune;

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
        production init(nt);

        CPPUNIT_ASSERT(!uninit.initialized());
        CPPUNIT_ASSERT(init.initialized());
    }
    
    void test_to_string()
    {
        non_terminal left("left");
        non_terminal right("right");
        literal l1("1");
        literal l2("2");

        production p(left, {{right, l1, l2}});

        std::string expected = "left = right, \"1\", \"2\"";
        CPPUNIT_ASSERT_EQUAL(expected, p.to_string());

        production p2(right, 
            {
                { l1, l2 },
                { left, left }
            }
        );

        expected = "right = \"1\", \"2\" | left, left";
        CPPUNIT_ASSERT_EQUAL(expected, p2.to_string());

        production p3(
            { left, right },
            {
                { l1, right },
                { left, l2 }
            }
        );

        expected = "left, right = \"1\", right | left, \"2\"";
        CPPUNIT_ASSERT_EQUAL(expected, p3.to_string());
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(production_test);
