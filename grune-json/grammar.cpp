#include "grune-json/grune-json.hpp"

#include "grune/grammar.hpp"

using namespace grune;

json11::Json grune::to_json(const grammar& value)
{
    return { };
}

bool grune::from_json(const json11::Json& js, grammar& )
{
    return false;
}

