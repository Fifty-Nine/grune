#include "unit_tests/tests.hpp"
#include "grune/all.hpp"

using namespace grune;

class production_test : public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(production_test);
    CPPUNIT_TEST(test_initialized);
    CPPUNIT_TEST(test_to_string);
    CPPUNIT_TEST(test_apply);
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
        symbol l1("1");
        symbol l2("2");

        production p(left, {{right, l1, l2}});

        std::string expected = "left = right, \"1\", \"2\"";
        CPPUNIT_ASSERT_EQUAL(expected, p.to_string());

        production p2_1(right, { { l1, l2 } });
        production p2_2(right, { { left, left } });
        production_list p2 { p2_1, p2_2 };

        expected = "right = \"1\", \"2\"";
        CPPUNIT_ASSERT_EQUAL(expected, to_string(p2_1));

        expected = "right = left, left";
        CPPUNIT_ASSERT_EQUAL(expected, to_string(p2_2));

        expected = "right = \"1\", \"2\" | left, left;\n";
        CPPUNIT_ASSERT_EQUAL(expected, to_string(p2));

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

    void test_apply()
    {
        non_terminal A("A");
        non_terminal B("B");
        non_terminal C("C");

        production p1
        {
            A,
            {
                { "b", "c" },
                { "d" }
            }
        };

        CPPUNIT_ASSERT(p1.apply({}).empty());

        sequence_list result = p1.apply({"x", A, "y"});
        CPPUNIT_ASSERT_EQUAL((int)result.size(), 2);

        sequence_list expected = 
        {
            { "x", "b", "c", "y" },
            { "x", "d", "y" }
        };
        CPPUNIT_ASSERT_EQUAL(result, expected);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(production_test);
