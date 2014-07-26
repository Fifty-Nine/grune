#include "grammar/grammar.hpp"

#include <sstream>

#include "grammar/production.hpp"
#include "grammar/types.hpp"

namespace grammar
{

grammar::grammar(const std::list<production*>& rules) : 
    m_rules(rules)
{
}

std::string grammar::to_string() const
{
    std::ostringstream result;

    for (auto p : m_rules)
    {
        result << ::grammar::to_string(*p);
        result << ";\n";
    }

    return result.str();
}

}
