#include "grune/all.hpp"

#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include "unit_tests/tests.hpp"

using namespace CppUnit;

CompilerOutputter *getOutputter(TestResultCollector& collector)
{
    CompilerOutputter *result = 
        new CompilerOutputter(&collector, std::cerr);

    result->setLocationFormat("%p:%l:");

    return result;
}

BOOST_AUTO_TEST_CASE(cppunit_main)
{
    TextTestRunner runner;
    runner.addTest(TestFactoryRegistry::getRegistry().makeTest());
    runner.setOutputter(getOutputter(runner.result()));
    BOOST_CHECK(runner.run("", false, true, false));
}
