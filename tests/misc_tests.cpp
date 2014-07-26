#include "tests/tests.hpp"
#include "grammar/all.hpp"

using namespace grammar;

class misc_tests : public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(misc_tests);
    CPPUNIT_TEST(test_is_terminal);
    CPPUNIT_TEST_SUITE_END();

public:
    void test_is_terminal()
    {
        literal lit("l");
        non_terminal nt("nt");
        sequence nt_seq { &lit, &nt };
        sequence t_seq { &lit, &lit };
        sentence s { &lit, &lit };

        CPPUNIT_ASSERT(is_terminal(lit));
        CPPUNIT_ASSERT(!is_terminal(nt)); 
        CPPUNIT_ASSERT(!is_terminal(nt_seq));
        CPPUNIT_ASSERT(is_terminal(t_seq));
        CPPUNIT_ASSERT(is_terminal(s));
    }
    
};

CPPUNIT_TEST_SUITE_REGISTRATION(misc_tests);
