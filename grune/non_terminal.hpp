#ifndef GRUNE_NON_TERMINAL_HPP
#define GRUNE_NON_TERMINAL_HPP

#include "grune/symbol.hpp"

namespace grune 
{

class non_terminal : public symbol
{
public:
    non_terminal(const std::string& identifier);

    std::string identifier() const;
    virtual std::string to_string() const;

private:
    std::string m_identifier;
};

} 

#endif /* GRUNE_NON_TERMINAL_HPP */
