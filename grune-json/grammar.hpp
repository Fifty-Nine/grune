#ifndef GRUNE_JSON_GRAMMAR_HPP
#define GRUNE_JSON_GRAMMAR_HPP

#include "grune-json/grune-json.hpp"

namespace grune
{

class grammar;

namespace json
{
namespace detail
{

template<>
struct json_traits<grammar>
{
    static void encode(const grammar& value, json11::Json& js);
    static grammar decode(const json11::Json& js);
};

}
}
}

#endif /* GRUNE_JSON_GRAMMAR_HPP */
