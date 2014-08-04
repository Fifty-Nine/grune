#include "grune-yaml/grune-yaml.hpp"

#include "grune/non_terminal.hpp"
#include "grune/symbol.hpp"

using namespace grune;

YAML::Node YAML::convert<grune::symbol>::encode(
    const grune::symbol& rhs)
{
    std::string prefix = "";
    if (!rhs.is_terminal())
    {
        prefix = "_";
    }
    else if (rhs.is_terminal() && !rhs.text().empty() && rhs.text()[0] == '_')
    {
        prefix = "\\";
    }

    return Node(prefix + rhs.text());
}

bool YAML::convert<grune::symbol>::decode(
    const YAML::Node& node, grune::symbol& rhs)
{
    std::string text = "";
    bool is_terminal = false;
    if (node.IsScalar() || node.IsNull())
    {
        text = node.Scalar();
        is_terminal = text.empty() || text[0] != '_';

        if (!is_terminal || (!text.empty() && text[0] == '\\'))
        {
            text = text.substr(1);
        }
    }
    else if (node.IsMap())
    {
        is_terminal = node["is_terminal"].as<bool>();
        text = node["text"].Scalar();
    }
    rhs = is_terminal ? 
        symbol(text) : non_terminal(text);
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
