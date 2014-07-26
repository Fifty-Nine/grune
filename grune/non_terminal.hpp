#ifndef GRAMMAR_NON_TERMINAL_HPP
#define GRAMMAR_NON_TERMINAL_HPP

#include "grammar/symbol.hpp"

namespace grammar 
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

#endif /* GRAMMAR_NON_TERMINAL_HPP */
