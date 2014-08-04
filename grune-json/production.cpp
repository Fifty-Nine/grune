#include "grune-json/grune-json.hpp"

#include "grune/production.hpp"

using namespace grune;
using namespace grune::json::detail;

void json_traits<production>::encode(const production& value, json11::Json& js)
{
}

production json_traits<production>::decode(json11::Json& js)
{
    return production();
}

