#ifndef GRAMMAR_GRAMMAR_H
#define GRAMMAR_GRAMMAR_H

#include <list>
#include <string>

namespace grammar
{

class production;

/* Represents a Type-0 (or higher) Chomsky grammar. */
class grammar
{
public:
    grammar(const std::list<production*>& rules);
    
    std::string to_string() const;

private:
    std::list<production*> m_rules;
};

}

#endif /* GRAMMAR_GRAMMAR_H */