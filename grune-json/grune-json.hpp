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
    static json11::Json encode(const T& value)
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
    return detail::json_traits<T>::encode(value);
}

template<class T>
T from_json(json11::Json value)
{
    return detail::json_traits<T>::decode(value);
}

}
}

#endif /* GRUNE_JSON_HPP */
