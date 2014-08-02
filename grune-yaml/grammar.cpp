#include "grune-yaml/grune-yaml.hpp"

#include "grune/grammar.hpp"
#include "grune/production.hpp"
#include "grune/symbol.hpp"

using namespace grune;

YAML::Node YAML::convert<grune::grammar>::encode(const grune::grammar& rhs)
{
    Node result;
    result["non_terminals"] = rhs.non_terminals();
    result["terminals"] = rhs.terminals();
    result["rules"] = rhs.productions();
    result["start"] = rhs.start_symbol();
    return result;
}

bool YAML::convert<grune::grammar>::decode(
    const YAML::Node& node, grune::grammar& rhs)
{
    rhs = 
    { 
        node["non_terminals"].as<grune::sequence>(),
        node["terminals"].as<grune::sequence>(),
        node["rules"].as<grune::production_list>(),
        node["start"].as<grune::symbol>()
    };
    return true;
}
