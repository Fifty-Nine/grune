#ifndef GRAMMAR_PRODUCTION_HPP
#define GRAMMAR_PRODUCTION_HPP

#include <list>

namespace grammar 
{

class non_terminal;
class symbol;

class production
{
public:
    production();
    production(non_terminal* from, std::initializer_list<symbol*> to = {});

    bool initialized() const;

private:
    non_terminal* m_from;
    std::list<symbol*> m_to;
};

}

#endif /* GRAMMAR_PRODUCTION_HPP */
