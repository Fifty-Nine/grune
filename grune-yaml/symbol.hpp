#ifndef GRUNE_YAML_SYMBOL_H
#define GRUNE_YAML_SYMBOL_H

#include <yaml-cpp/yaml.h>

namespace grune 
{ 
    class symbol; 
    class non_terminal; 
}

namespace YAML
{

template<>
struct convert<grune::symbol>
{
    static Node encode(const grune::symbol& rhs);
    static bool decode(const Node& node, grune::symbol& rhs);
};

template<>
struct convert<grune::non_terminal> : 
    public convert<grune::symbol>
{ 
    static bool decode(const Node& node, grune::non_terminal& rhs);
};

}

#endif /* GRUNE_YAML_SYMBOL_H */
