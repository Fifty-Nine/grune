#include "grammar/literal.hpp"

using namespace grammar;

literal::literal(const std::string &text) : 
    m_text(text)
{
}

std::string literal::text() const
{
    return m_text;
}

std::string literal::to_string() const
{
    return m_text;
}
