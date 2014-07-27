#include "tests/tests.hpp"
#include "grune/all.hpp"

using namespace grune;

class misc_tests : public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(misc_tests);
    CPPUNIT_TEST(test_is_terminal);
    CPPUNIT_TEST(test_is_empty);
    CPPUNIT_TEST_SUITE_END();

public:
    void test_is_terminal()
    {
        literal lit("l");
        literal empty;
        non_terminal nt("nt");
        sequence nt_seq { lit, nt };
        sequence t_seq { lit, lit };
        sequence s { lit, lit };

        CPPUNIT_ASSERT(is_terminal(lit));
        CPPUNIT_ASSERT(is_terminal(empty));
        CPPUNIT_ASSERT(!is_terminal(nt)); 
        CPPUNIT_ASSERT(!is_terminal(nt_seq));
        CPPUNIT_ASSERT(is_terminal(t_seq));
        CPPUNIT_ASSERT(is_terminal(s));

        production ntp { nt, { nt_seq, t_seq } };
        production tp { nt, { t_seq } };

        CPPUNIT_ASSERT(!is_terminal(ntp));
        CPPUNIT_ASSERT(is_terminal(tp));
    }
    
    void test_is_empty()
    {
        literal lit("l");
        literal empty;
        non_terminal nt("nt");

        CPPUNIT_ASSERT(!is_empty(lit));
        CPPUNIT_ASSERT(is_empty(empty));
        CPPUNIT_ASSERT(!is_empty(nt));
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(misc_tests);
