#include "grune-json/grune-json.hpp"

#include "grune/production.hpp"

using namespace grune;
using namespace grune::json::detail;

json11::Json json_traits<production>::encode(const production& value)
{
    return { };
}

production json_traits<production>::decode(const json11::Json& js)
{
    return { };
}

