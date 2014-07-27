#ifndef GRUNE_SYMBOL_HPP
#define GRUNE_SYMBOL_HPP

#include <string>

namespace grune 
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

    /* 
     * Test whether this symbol is the empty string.
     */
    virtual bool is_empty() const { return false; }
};

};

#endif /* GRUNE_SYMBOL_HPP */
