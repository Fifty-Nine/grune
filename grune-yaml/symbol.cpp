#include "grune-yaml/grune-yaml.hpp"

YAML::Node YAML::convert<grune::symbol>::encode(
    const grune::symbol& rhs)
{
    return YAML::Node();
}

bool YAML::convert<grune::symbol>::decode(
    const YAML::Node& node, grune::symbol& rhs)
{
    return false;
}

bool YAML::convert<grune::non_terminal>::decode(
    const YAML::Node& node, grune::non_terminal& rhs)
{ 
    return false;
}
