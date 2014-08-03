#include "grune-yaml/grune-yaml.hpp"

#include "grune/production.hpp"

using namespace grune;

YAML::Node YAML::convert<grune::production>::encode(
    const grune::production& in)
{
    Node result;

    if (in.initialized())
    {
        auto rhs = in.rhs();
        result["lhs"] = in.lhs();
        result["rhs"] = rhs.empty() ? sequence() : rhs.front();
    }
    else
    {
        result = YAML::Null;
    }
    return result;
}

bool YAML::convert<grune::production>::decode(
    const YAML::Node& node, grune::production& out)
{
    if (!node.IsNull() && !node.IsScalar())
    {
        sequence lhs = node["lhs"].as<sequence>();
        sequence rhs = node["rhs"].as<sequence>();
        out = production(lhs, 
            rhs.empty() ? sequence_list { { } } : sequence_list { rhs });
    }
    else
    {
        out = grune::production();
    }

    return true;
}
