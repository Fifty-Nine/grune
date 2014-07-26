#ifndef GRUNE_NON_TERMINAL_HPP
#define GRUNE_NON_TERMINAL_HPP

#include "grune/grune_fwd.hpp"
#include "grune/symbol.hpp"

namespace grune 
{

class non_terminal : public symbol
{
public:
    non_terminal(const std::string& identifier);
    static non_terminal_ptr create(const std::string& identifier);

    std::string identifier() const;
    virtual std::string to_string() const;

private:
    std::string m_identifier;
};

} 

#endif /* GRUNE_NON_TERMINAL_HPP */
