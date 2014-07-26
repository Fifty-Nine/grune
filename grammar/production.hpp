#ifndef GRAMMAR_PRODUCTION_HPP
#define GRAMMAR_PRODUCTION_HPP

#include <list>
#include <string>

#include "grammar/types.hpp"

namespace grammar 
{

class non_terminal;
class symbol;

class production
{
public:
    production();
    production(non_terminal* from, const std::list<sequence>& to = {});
    production(const sequence& from, const std::list<sequence>& to = {});

    bool initialized() const;

    std::string to_string() const;

private:
    sequence m_from;
    std::list<sequence> m_to;
};

}

#endif /* GRAMMAR_PRODUCTION_HPP */
