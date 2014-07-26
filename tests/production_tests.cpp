#include "tests/tests.hpp"
#include "grammar/non_terminal.hpp"
#include "grammar/production.hpp"

using namespace grammar;

class production_test : public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(production_test);
    CPPUNIT_TEST(testInitialized);
    CPPUNIT_TEST_SUITE_END();

public:
    void testInitialized()
    {
        non_terminal nt;
        production uninit;
        production init(&nt);

        CPPUNIT_ASSERT(!uninit.initialized());
        CPPUNIT_ASSERT(init.initialized());
    }
    
};

CPPUNIT_TEST_SUITE_REGISTRATION(production_test);
