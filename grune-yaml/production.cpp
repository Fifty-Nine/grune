#include "grune-yaml/grune-yaml.hpp"

#include "grune/production.hpp"

using namespace grune;

YAML::Node YAML::convert<grune::production>::encode(
    const grune::production& rhs)
{
    Node result;
    result["lhs"] = rhs.lhs();
    result["rhs"] = rhs.rhs();
    return result;
}

bool YAML::convert<grune::production>::decode(
    const YAML::Node& node, grune::production& out)
{
    sequence lhs = node["lhs"].as<sequence>();
    sequence_list rhs = node["rhs"].as<sequence_list>();
    out = production(lhs, rhs);
    return true;
}
