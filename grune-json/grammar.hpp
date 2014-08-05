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
    static json11::Json encode(const grammar& value);
    static grammar decode(const json11::Json& js);
};

}
}
}

#endif /* GRUNE_JSON_GRAMMAR_HPP */
