#include "grune-json/grune-json.hpp"

#include "grune/grammar.hpp"

using namespace grune;
using namespace json11;

Json grune::to_json(const grammar& value)
{
    return Json::object {
        { "non_terminals", value.non_terminals() },
        { "terminals", value.terminals() },
        { "rules", value.productions() },
        { "start", value.start_symbol() }
    };
}

bool grune::from_json(const Json& js, grammar& g)
{
    g = {
        js["non_terminals"].as<sequence>(),
        js["terminals"].as<sequence>(),
        js["rules"].as<production_list>(),
        js["start"].as<symbol>()
    };
    return true;
}

