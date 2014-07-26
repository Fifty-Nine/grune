#ifndef GRAMMAR_TYPES_H
#define GRAMMAR_TYPES_H

#include <list>
#include <string>

namespace grammar
{

class symbol;
class terminal;
class production;

typedef std::list<symbol*> sequence;
typedef std::list<terminal*> sentence;

std::string to_string(const sequence& s);
std::string to_string(const sentence& s);
std::string to_string(const symbol& s);
std::string to_string(const production& p);

}

#endif /* GRAMMAR_TYPES_H */
