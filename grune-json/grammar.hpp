#ifndef GRUNE_JSON_GRAMMAR_HPP
#define GRUNE_JSON_GRAMMAR_HPP

#include <json11/json11.hpp>

#include "grune-json/grune-json.hpp"

namespace grune
{

class grammar;

json11::Json to_json(const grammar& g);
bool from_json(const json11::Json& js, grammar& g);

}

#endif /* GRUNE_JSON_GRAMMAR_HPP */
