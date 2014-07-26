#ifndef GRAMMAR_TERMINAL_HPP
#define GRAMMAR_TERMINAL_HPP

#include "grammar/symbol.hpp"

namespace grammar
{

class terminal : public symbol
{
public:
    virtual bool is_terminal() const { return true; }
};

}

#endif /* GRAMMAR_TERMINAL_HPP */
