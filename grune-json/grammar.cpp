#include "grune-json/grune-json.hpp"

#include "grune/grammar.hpp"

using namespace grune;
using namespace grune::json::detail;

void json_traits<grammar>::encode(const grammar& value, json11::Json& js)
{
}

grammar json_traits<grammar>::decode(json11::Json& js)
{
    return grammar();
}

