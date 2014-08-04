#include "grune-json/grune-json.hpp"

#include "grune/symbol.hpp"

using namespace grune;
using namespace grune::json::detail;

void json_traits<symbol>::encode(const symbol& value, json11::Json& js)
{
}

symbol json_traits<symbol>::decode(json11::Json& js)
{
    return symbol();
}

