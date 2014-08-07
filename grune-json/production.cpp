#include "grune-json/grune-json.hpp"

#include "grune/production.hpp"

using namespace grune;

json11::Json grune::to_json(const production& value)
{
    return { };
}

bool grune::from_json(const json11::Json& js, production& p)
{
    return false;
}

