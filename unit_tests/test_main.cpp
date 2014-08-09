#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include "unit_tests/tests.hpp"

struct TestInit
{
    TestInit();
};

TestInit::TestInit()
{
#ifdef COVERITY_BUILD
    COVERITY_TS_SET_SUITE_NAME("unit_tests");
#endif /* COVERITY_BUILD */
}

BOOST_GLOBAL_FIXTURE(TestInit);
