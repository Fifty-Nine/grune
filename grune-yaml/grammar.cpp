#include "grune-yaml/grune-yaml.hpp"

YAML::Node YAML::convert<grune::grammar>::encode(const grune::grammar& rhs)
{
    return YAML::Node();
}

bool YAML::convert<grune::grammar>::decode(
    const YAML::Node& node, grune::grammar& rhs)
{
    return false;
}
