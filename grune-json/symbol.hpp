#ifndef GRUNE_JSON_SYMBOL_HPP
#define GRUNE_JSON_SYMBOL_HPP

#include "grune-json/grune-json.hpp"

namespace grune
{

class symbol;

namespace json
{
namespace detail
{

template<>
struct json_traits<symbol>
{
    static void encode(const symbol& value, json11::Json& js);
    static symbol decode(json11::Json& js);
};

}
}
}

#endif /* GRUNE_JSON_SYMBOL_HPP */
