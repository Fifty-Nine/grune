#include "non_terminal.hpp"

using namespace grune;

non_terminal::non_terminal(const std::string &identifier) : 
    m_identifier(identifier)
{
}

non_terminal_ptr non_terminal::create(const std::string& identifier)
{
    return std::make_shared<non_terminal>(identifier);
}

std::string non_terminal::identifier() const 
{
    return m_identifier;
}

std::string non_terminal::to_string() const 
{
    return m_identifier;
}
