#include "grune-json/grune-json.hpp"

#include "grune/production.hpp"

using namespace grune;
using namespace json11;

Json grune::to_json(const production& value)
{
    Json lhs(value.lhs());
    Json rhs(value.rhs());
    return Json::object { 
        { "lhs", lhs },
        { "rhs", rhs }
    };
}

bool grune::from_json(const Json& js, production& p)
{
    sequence lhs = js["lhs"].as<sequence>();
    sequence rhs = js["rhs"].as<sequence>();
    p = production(lhs, rhs);
    return true;
}

