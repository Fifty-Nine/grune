#include "grune-yaml/grune-yaml.hpp"

YAML::Node YAML::convert<grune::production>::encode(
    const grune::production& rhs)
{
    return YAML::Node();
}

bool YAML::convert<grune::production>::decode(
    const YAML::Node& node, grune::production& rhs)
{
    return false;
}
