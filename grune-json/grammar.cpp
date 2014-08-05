#include "grune-json/grune-json.hpp"

#include "grune/grammar.hpp"

using namespace grune;
using namespace grune::json::detail;

json11::Json json_traits<grammar>::encode(const grammar& value)
{
    return { };
}

grammar json_traits<grammar>::decode(const json11::Json& js)
{
    return { };
}

