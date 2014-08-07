#ifndef GRUNE_JSON_SYMBOL_HPP
#define GRUNE_JSON_SYMBOL_HPP

#include "grune-json/grune-json.hpp"

namespace grune
{

class non_terminal;
class symbol;

json11::Json to_json(const symbol& s);
json11::Json to_json(const non_terminal& s);
bool from_json(const json11::Json& js, symbol& s);
bool from_json(const json11::Json& js, non_terminal& nt);

}

#endif /* GRUNE_JSON_SYMBOL_HPP */
