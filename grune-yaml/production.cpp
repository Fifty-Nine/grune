#include "grune-yaml/grune-yaml.hpp"

#include "grune/production.hpp"

using namespace grune;

namespace
{

sequence get(const YAML::Node& n)
{
    return 
        n.IsSequence() ? n.as<sequence>() : 
        n.IsNull() ? sequence() :
        sequence { n.as<symbol>() };
}

void put(YAML::Node n, const sequence& s)
{
    if (s.size() == 1) { n = s.front(); }
    else { n = s; }
}

}

YAML::Node YAML::convert<grune::production>::encode(
    const grune::production& in)
{
    Node result;

    if (in.initialized())
    {
        put(result["lhs"], in.lhs());
        put(result["rhs"], in.rhs());
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
    out = node.IsNull() || node.IsScalar() ? 
        production() : 
        production(
            get(node["lhs"]),
            get(node["rhs"])
        );
    return true;
}
