#ifndef GRUNE_YAML_GRAMMAR_H
#define GRUNE_YAML_GRAMMAR_H

#include <yaml-cpp/yaml.h>

namespace grune { class grammar; }

namespace YAML
{

template<>
struct convert<grune::grammar>
{
    static Node encode(const grune::grammar& rhs);
    static bool decode(const Node& node, grune::grammar& rhs);
};

}

#endif /* GRUNE_YAML_GRAMMAR_H */
