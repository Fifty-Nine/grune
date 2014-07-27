#include "grune/all.hpp"

#include "unit_tests/tests.hpp"

using namespace CppUnit;

CompilerOutputter *getOutputter(TestResultCollector& collector)
{
    CompilerOutputter *result = 
        new CompilerOutputter(&collector, std::cerr);

    result->setLocationFormat("%p:%l:");

    return result;
}

int main() 
{
    TextTestRunner runner;
    runner.addTest(TestFactoryRegistry::getRegistry().makeTest());
    runner.setOutputter(getOutputter(runner.result()));
    return !runner.run("", false, true, false);
}
