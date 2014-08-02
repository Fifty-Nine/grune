#ifndef GRUNE_FWD_H
#define GRUNE_FWD_H

#include <list>

namespace grune 
{

class grammar;
class non_terminal;
class production;
class symbol;

typedef std::list<symbol> sequence;
typedef std::list<sequence> sequence_list;
typedef std::list<production> production_list;

} 

#endif /* GRUNE_FWD_H */
