#include "grune/grammars/anbncn.hpp"
#include "grune/grammars/turtle.hpp"
#include "grune/grammars/tom_dick_and_harry.hpp"
#include "grune-yaml/grune-yaml.hpp"

#include <fstream>

#define MAKE_SAMPLE_IMPL(name) \
    do { \
        std::ofstream out(#name ".yaml"); \
        out << YAML::Node(grune::grammars::name()) << std::endl; \
    } while(0)

#ifndef COVERITY_BUILD
#define MAKE_SAMPLE(name) MAKE_SAMPLE_IMPL(name)
#else
#include <coverity-test-separation.h>
#define MAKE_SAMPLE(name) \
    do { \
        COVERITY_TS_START_TEST(#name); \
        MAKE_SAMPLE_IMPL(name); \
        COVERITY_TS_END_TEST(); \
    } while(0)
#endif

int main()
{
#ifdef COVERITY_BUILD
    COVERITY_TS_SET_SUITE_NAME("grune-yaml/make-samples");
#endif
    MAKE_SAMPLE(anbncn);
    MAKE_SAMPLE(cyclic_manhattan_turtle);
    MAKE_SAMPLE(tom_dick_and_harry);
}
