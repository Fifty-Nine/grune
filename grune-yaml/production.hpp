#ifndef GRUNE_YAML_PRODUCTION_H
#define GRUNE_YAML_PRODUCTION_H

#include <yaml-cpp/yaml.h>

namespace grune { class production; } 

namespace YAML
{

template<>
struct convert<grune::production>
{
    static Node encode(const grune::production& rhs);
    static bool decode(const Node& node, grune::production& rhs);
};

}

#endif /* GRUNE_YAML_PRODUCTION_H */
