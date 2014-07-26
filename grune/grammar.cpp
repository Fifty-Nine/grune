#include "grune/grammar.hpp"

#include <sstream>

#include "grune/production.hpp"
#include "grune/types.hpp"

using namespace grune;

grammar::grammar(const std::list<production*>& rules) : 
    m_rules(rules)
{
}

std::string grammar::to_string() const
{
    std::ostringstream result;

    for (auto p : m_rules)
    {
        result << grune::to_string(*p);
        result << ";\n";
    }

    return result.str();
}

