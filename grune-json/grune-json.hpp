#ifndef GRUNE_JSON_HPP
#define GRUNE_JSON_HPP

#include "json11/json11.hpp"

namespace grune
{
namespace json
{
namespace detail
{

template<class T>
struct json_traits
{
    static void encode(const T& value, json11::Json& js)
    {
    }

    static T decode(const json11::Json& js)
    {
        return T();
    }
};

}
}
}

#include "grune-json/grammar.hpp"
#include "grune-json/production.hpp"
#include "grune-json/symbol.hpp"

namespace grune
{
namespace json
{

template<class T>
json11::Json to_json(T value)
{
    json11::Json result;
    detail::json_traits<T>::encode(value, result);
    return result;
}

template<class T>
T from_json(json11::Json value)
{
    return detail::json_traits<T>::decode(value);
}

}
}

#endif /* GRUNE_JSON_HPP */
