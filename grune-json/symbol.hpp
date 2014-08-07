#ifndef GRUNE_JSON_SYMBOL_HPP
#define GRUNE_JSON_SYMBOL_HPP

#include "grune-json/grune-json.hpp"
#include "grune/grune_fwd.hpp"

namespace grune
{

json11::Json to_json(const symbol& s);
json11::Json to_json(const non_terminal& s);
json11::Json to_json(const sequence& s);
bool from_json(const json11::Json& js, symbol& s);
bool from_json(const json11::Json& js, non_terminal& nt);
bool from_json(const json11::Json& js, sequence& s);

}

#endif /* GRUNE_JSON_SYMBOL_HPP */
