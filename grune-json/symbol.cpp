#include "grune-json/grune-json.hpp"

#include "grune/non_terminal.hpp"
#include "grune/symbol.hpp"

using namespace grune;
using namespace grune::json::detail;

void json_traits<symbol>::encode(const symbol& v, json11::Json& js)
{
    std::string prefix = "";
    if (!v.is_terminal())
    {
        prefix = "_";
    }
    else if (v.is_terminal() && !v.text().empty() && v.text()[0] == '_')
    {
        prefix = "\\";
    }
    js = json11::Json(prefix + v.text());
}

symbol json_traits<symbol>::decode(const json11::Json& js)
{
    std::string text = "";
    bool is_terminal = false;
    if (js.is_null() || js.is_number() || js.is_string() || js.is_bool())
    {
        text = js.string_value();
        is_terminal = text.empty() || text[0] != '_';

        if (!is_terminal || (!text.empty() && text[0] == '\\'))
        {
            text = text.substr(1);
        }
    }
    else if (js.is_object())
    {
        auto obj = js.object_items();
        is_terminal = obj["is_terminal"].bool_value();
        text = obj["text"].string_value();
    }
    return is_terminal ? 
        symbol(text) : non_terminal(text);
}

non_terminal json_traits<non_terminal>::decode(const json11::Json& js)
{
    return grune::non_terminal(json_traits<symbol>::decode(js).identifier());
}
