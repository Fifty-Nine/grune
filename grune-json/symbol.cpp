#include "grune-json/grune-json.hpp"

#include "grune/non_terminal.hpp"
#include "grune/symbol.hpp"

using namespace grune;

json11::Json grune::to_json(const symbol& v)
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
    return { prefix + v.text() };
}

json11::Json grune::to_json(const non_terminal& nt)
{
    return grune::to_json(symbol(nt));
}

bool grune::from_json(const json11::Json& js, symbol& s)
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
    s = is_terminal ? 
        symbol(text) : non_terminal(text);
    return true;
}

bool grune::from_json(const json11::Json& js, non_terminal& nt)
{
    symbol result;
    if (from_json(js, result) && !result.is_terminal())
    {
        nt = result.identifier();
        return true;
    }
    return false;
}
