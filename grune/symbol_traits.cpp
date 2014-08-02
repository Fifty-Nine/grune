#include "grune/symbol_traits.hpp"

#include <sstream>

#include "grune/production.hpp"
#include "grune/symbol.hpp"

using namespace grune;

bool symbol_traits<production_list>::is_terminal(const production_list& p)
{
    return all_of(p.begin(), p.end(), &grune::is_terminal<production>);
}

bool symbol_traits<production_list>::is_empty(const production_list& p)
{
    return p.empty();
}

std::string symbol_traits<production_list>::to_string(const production_list& ps)
{
    std::ostringstream out;
    for (auto p : ps)
    {
        out << grune::to_string(p) << ";" << std::endl;
    }
    return out.str();
}


