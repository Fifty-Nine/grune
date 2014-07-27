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
        auto A = non_terminal::create("A");
        auto B = non_terminal::create("B");
        auto C = non_terminal::create("C");

        auto a = literal::create("a");
        auto b = literal::create("b");
        auto c = literal::create("c");

        auto p1 = production::create(
            A.get(), sequence_list { { a, B } }
        );        
        auto p2 = production::create(
            B.get(), sequence_list { { b, C } }
        );
        auto p3 = production::create(
            C.get(), sequence_list { { c }, { } }
        );

        return grammar(
            { A, B, C },
            { a, b, c },
            { p1, p2, p3 },
            A.get()
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
