#include "grune/grammars/anbncn.hpp"
#include "grune/grammars/turtle.hpp"
#include "grune/grammars/tom_dick_and_harry.hpp"
#include "grune-yaml/grune-yaml.hpp"

#include <fstream>

#define MAKE_SAMPLE(name) \
    do { \
        std::ofstream out(#name ".yaml"); \
        out << YAML::Node(grune::grammars::name()) << std::endl; \
    } while(0)

int main()
{
    MAKE_SAMPLE(anbncn);
    MAKE_SAMPLE(cyclic_manhattan_turtle);
    MAKE_SAMPLE(tom_dick_and_harry);
}
