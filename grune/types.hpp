#ifndef GRUNE_TYPES_H
#define GRUNE_TYPES_H

#include <list>
#include <string>

namespace grune
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

bool is_terminal(const sequence& s);
bool is_terminal(const sentence& s);
bool is_terminal(const symbol& s);
bool is_terminal(const production& p);

}

#endif /* GRUNE_TYPES_H */
