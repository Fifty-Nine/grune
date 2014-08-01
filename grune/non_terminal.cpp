#include "non_terminal.hpp"

using namespace grune;

non_terminal::non_terminal(const std::string &identifier) : 
    m_identifier(identifier)
{
}

std::string non_terminal::identifier() const 
{
    return m_identifier;
}

std::string non_terminal::to_string() const 
{
    return m_identifier;
}

std::string non_terminal::text() const 
{ 
    return m_identifier; 
}
