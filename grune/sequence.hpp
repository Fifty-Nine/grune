#ifndef GRUNE_SEQUENCE_H
#define GRUNE_SEQUENCE_H

#include "grune/grune_fwd.hpp"

#include <list>
#include <string>

namespace grune 
{

class sequence : public std::list<symbol*>
{
    typedef std::list<symbol*> base;
public:
    sequence(const std::initializer_list<symbol*>& seq = { });
    sequence(const std::list<symbol*>& seq);
    sequence(const std::list<symbol_ptr>& seq);
};

}

#endif /* GRUNE_SEQUENCE_H */
