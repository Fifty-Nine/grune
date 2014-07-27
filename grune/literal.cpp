#include "grune/literal.hpp"

using namespace grune;

literal::literal(const std::string &text) : 
    m_text(text)
{
}

literal_ptr literal::create(const std::string& text)
{
    return std::make_shared<literal>(text);
}

std::string literal::text() const
{
    return m_text;
}

std::string literal::to_string() const
{
    return "\"" + m_text + "\"";
}

bool literal::is_empty() const
{
    return m_text.empty();
}
