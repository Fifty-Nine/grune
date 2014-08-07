#ifndef GRUNE_JSON_PRODUCTION_HPP
#define GRUNE_JSON_PRODUCTION_HPP

#include "grune-json/grune-json.hpp"

namespace grune
{

class production;

json11::Json to_json(const production& p);
bool from_json(const json11::Json& js, production& p);

}

#endif /* GRUNE_JSON_PRODUCTION_HPP */
