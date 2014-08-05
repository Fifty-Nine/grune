#ifndef GRUNE_JSON_PRODUCTION_HPP
#define GRUNE_JSON_PRODUCTION_HPP

#include "grune-json/grune-json.hpp"

namespace grune
{

class production;

namespace json
{
namespace detail
{

template<>
struct json_traits<production>
{
    static json11::Json encode(const production& value);
    static production decode(const json11::Json& js);
};

}
}
}

#endif /* GRUNE_JSON_PRODUCTION_HPP */
