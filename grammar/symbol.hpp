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
};

};

#endif /* GRAMMAR_SYMBOL_HPP */
