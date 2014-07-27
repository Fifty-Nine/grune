#ifndef GRUNE_TYPES_H
#define GRUNE_TYPES_H

#include <list>
#include <string>

#include "grune/grune_fwd.hpp"
#include "grune/sequence.hpp"
#include "grune/sentence.hpp"

namespace grune
{

class symbol;
class terminal;
class production;

typedef std::list<sequence> sequence_list;
typedef std::list<sentence> sentence_list;
typedef std::list<production> production_list;

std::string to_string(const sequence& s);
std::string to_string(const sentence& s);
std::string to_string(const symbol& s);
std::string to_string(const production& p);

bool is_terminal(const sequence& s);
bool is_terminal(const sentence& s);
bool is_terminal(const symbol& s);
bool is_terminal(const production& p);

bool is_empty(const symbol& s);
}

#endif /* GRUNE_TYPES_H */
