#ifndef GRAMMAR_PRODUCTION_HPP
#define GRAMMAR_PRODUCTION_HPP

#include <list>

#include "grammar/non_terminal.hpp"

namespace grammar 
{

class production
{
public:
    production();
    production(non_terminal* from, std::initializer_list<symbol*> to);

    bool initialized() const;

private:
    non_terminal* m_from;
    std::list<symbol*> m_to;
};

};

#endif /* GRAMMAR_PRODUCTION_HPP */
