#ifndef GRAMMAR_SYMBOL_HPP
#define GRAMMAR_SYMBOL_HPP

#include <string>

namespace grammar 
{

class symbol 
{
public:
    /*
     * Convert the symbol into a string appropriate for pretty-printing. 
     */
    virtual std::string to_string() const = 0;

    /* 
     * Test whether this symbol is terminal.
     */
    virtual bool is_terminal() const { return false; }
};

};

#endif /* GRAMMAR_SYMBOL_HPP */
