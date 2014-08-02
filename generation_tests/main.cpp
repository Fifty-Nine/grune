#include "grune/all.hpp"

#include <boost/filesystem.hpp>
#include <fstream>

#define ADD_TEST(name) \
    extern void name(std::ostream&);

ADD_TEST(test_anbncn);
ADD_TEST(test_numbers);
ADD_TEST(test_numbers_simple);
ADD_TEST(test_tdh);
ADD_TEST(test_turtle);

typedef void (*test_fcn_t)(std::ostream&);
void run_test(test_fcn_t test, const std::string& name)
{
    std::cout << "Running test " << name << "..." << std::endl;
    std::ofstream results("./results/" + name + ".results");
    test(results);
}

#define RUN_TEST(name) run_test(name, #name)

int main()
{
    RUN_TEST(test_anbncn);
    RUN_TEST(test_numbers_simple);
    RUN_TEST(test_numbers);
    RUN_TEST(test_turtle);
    RUN_TEST(test_tdh);

    return 0;
}

