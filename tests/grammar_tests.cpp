#include "tests/tests.hpp"
#include "grune/all.hpp"

using namespace grune;

class grammar_tests : public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(grammar_tests);
    CPPUNIT_TEST(test_to_string);
    CPPUNIT_TEST_SUITE_END();

    grammar test_grammar() const
    {
        non_terminal A("A");
        non_terminal B("B");
        non_terminal C("C");

        literal a("a");
        literal b("b");
        literal c("c");

        production p1(
            A, { { a, B } }
        );        
        production p2(
            B, { { b, C } }
        );
        production p3(
            C, { { c }, { } }
        );

        return grammar(
            { A, B, C },
            { a, b, c },
            { p1, p2, p3 }, 
            A
        );
    }

public:
    void test_to_string()
    {
        std::string expected = 
            "A = \"a\", B;\n"
            "B = \"b\", C;\n"
            "C = \"c\" | \"\";\n";
        CPPUNIT_ASSERT_EQUAL(expected, test_grammar().to_string());
    }
    
};

CPPUNIT_TEST_SUITE_REGISTRATION(grammar_tests);
