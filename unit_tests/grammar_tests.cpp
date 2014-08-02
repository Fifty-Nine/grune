#include "unit_tests/tests.hpp"
#include "grune/all.hpp"

using namespace grune;

class grammar_tests : public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(grammar_tests);
    CPPUNIT_TEST(test_to_string);
    CPPUNIT_TEST(test_generate);
    CPPUNIT_TEST_SUITE_END();

    grammar test_grammar() const
    {
        non_terminal A("A");
        non_terminal B("B");
        non_terminal C("C");

        symbol a("a");
        symbol b("b");
        symbol c("c");

        production p1(
            A, { { a, B } }
        );        
        production p2(
            B, { { b, C } }
        );
        production p3(
            C, { { c } }
        );
        production p4(
            C, { { } }
        );

        return grammar(
            { A, B, C },
            { a, b, c },
            { p1, p2, p3, p4 }, 
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

    void test_generate()
    {
        grammar g = test_grammar();

        const sentence_iterator begin(g);
        const sentence_iterator end;
        auto it = begin;

        sequence first = { "a", "b", "c" };
        sequence second = { "a", "b" };

        CPPUNIT_ASSERT_EQUAL(*it, first);
        CPPUNIT_ASSERT_EQUAL(*it++, first);
        CPPUNIT_ASSERT_EQUAL(*it, second);
        CPPUNIT_ASSERT_EQUAL(++it, end); 

        sequence_list expected 
        {
            { "a", "b", "c" },
            { "a", "b" }
        };

        sequence_list actual(begin, end);
        CPPUNIT_ASSERT_EQUAL(actual, expected);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(grammar_tests);
