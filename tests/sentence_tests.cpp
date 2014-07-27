#include "tests/tests.hpp"
#include "grune/literal.hpp"
#include "grune/non_terminal.hpp"
#include "grune/sentence.hpp"
#include "grune/types.hpp"

using namespace grune;

class sentence_tests : public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(sentence_tests);
    CPPUNIT_TEST(test_to_string);
    CPPUNIT_TEST_SUITE_END();

public:
    void test_to_string()
    {
        auto a = literal::create("a");
        auto b = literal::create("b");
        auto c = literal::create("c");

        std::list<terminal*> l1 { a.get(), b.get(), c.get() };
        std::list<terminal_ptr> l2 { a, b, c };

        sentence s1 { a, b, c };
        sentence s2 { a.get(), b.get(), c.get() };
        sentence s3(l1);
        sentence s4(l2);

        std::string expected = "\"a\", \"b\", \"c\"";
        CPPUNIT_ASSERT_EQUAL(expected, to_string(s1));
        CPPUNIT_ASSERT_EQUAL(expected, to_string(s2));
        CPPUNIT_ASSERT_EQUAL(expected, to_string(s3));
        CPPUNIT_ASSERT_EQUAL(expected, to_string(s4));

        auto empty = literal::create();
        sentence empty1;
        sentence empty2 { empty };

        expected = "\"\"";
        CPPUNIT_ASSERT_EQUAL(expected, to_string(empty1));
        CPPUNIT_ASSERT_EQUAL(expected, to_string(empty2));
    }
    
};

CPPUNIT_TEST_SUITE_REGISTRATION(sentence_tests);
