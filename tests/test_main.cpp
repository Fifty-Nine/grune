#include "grammar/all.hpp"

#include "tests/tests.hpp"

using namespace CppUnit;

int main() {
    TextUi::TestRunner runner;
    runner.addTest(TestFactoryRegistry::getRegistry().makeTest());
    return !runner.run();
}
