#ifndef GRUNE_YAML_SYMBOL_H
#define GRUNE_YAML_SYMBOL_H

#include <yaml-cpp/yaml.h>

namespace grune { class symbol; }

namespace YAML
{

template<>
struct convert<grune::symbol>
{
    static Node encode(const grune::symbol& rhs);
    static bool decode(const Node& node, grune::symbol& rhs);
};

}

#endif /* GRUNE_YAML_SYMBOL_H */
