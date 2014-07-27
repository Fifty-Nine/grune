#include "tests/tests.hpp"
#include "grune/literal.hpp"
#include "grune/non_terminal.hpp"
#include "grune/sequence.hpp"
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
        auto A = non_terminal::create("A");
        auto B = non_terminal::create("B");
        auto c = literal::create("c");

        std::list<symbol*> l1 { A.get(), B.get(), c.get() };
        std::list<symbol_ptr> l2 { A, B, c };

        sequence s1 { A, B, c };
        sequence s2 { A.get(), B.get(), c.get() };
        sequence s3(l1);
        sequence s4(l2);

        std::string expected = "A, B, \"c\"";
        CPPUNIT_ASSERT_EQUAL(expected, to_string(s1));
        CPPUNIT_ASSERT_EQUAL(expected, to_string(s2));
        CPPUNIT_ASSERT_EQUAL(expected, to_string(s3));
        CPPUNIT_ASSERT_EQUAL(expected, to_string(s4));

        expected = "\"\"";
        CPPUNIT_ASSERT_EQUAL(expected, to_string(sequence()));
    }
    
};

CPPUNIT_TEST_SUITE_REGISTRATION(sequence_tests);
