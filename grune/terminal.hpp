#ifndef GRUNE_TERMINAL_HPP
#define GRUNE_TERMINAL_HPP

#include "grune/symbol.hpp"

namespace grune
{

class terminal : public symbol
{
public:
    virtual bool is_terminal() const { return true; }
};

}

#endif /* GRUNE_TERMINAL_HPP */
