#include "grune-yaml/grune-yaml.hpp"

#include "grune/non_terminal.hpp"
#include "grune/symbol.hpp"

using namespace grune;

YAML::Node YAML::convert<grune::symbol>::encode(
    const grune::symbol& rhs)
{
    Node result;

    if (rhs.is_terminal())
    {
        result = Node(rhs.text());
    }
    else
    {
        result["text"] = rhs.text();
        result["is_terminal"] = rhs.is_terminal();
    }
    return result;
}

bool YAML::convert<grune::symbol>::decode(
    const YAML::Node& node, grune::symbol& rhs)
{
    if (node.IsScalar() || node.IsNull())
    {
        rhs = symbol(node.Scalar());
    }
    else if (node.IsMap())
    {
        bool is_terminal = node["is_terminal"].as<bool>();
        std::string text = node["text"].Scalar();

        rhs = is_terminal ? 
            symbol(text) : non_terminal(text);
    }
    return true;
}

bool YAML::convert<grune::non_terminal>::decode(
    const YAML::Node& node, grune::non_terminal& rhs)
{ 
    grune::symbol s = node.as<grune::symbol>();

    if (s.is_terminal()) return false;  

    rhs = grune::non_terminal(s.identifier());
    return true;
}
