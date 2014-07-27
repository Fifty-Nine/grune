#ifndef GRUNE_SENTENCE_H
#define GRUNE_SENTENCE_H

#include "grune/sequence.hpp"

namespace grune
{

class sentence : public std::list<terminal*> 
{
    typedef std::list<terminal*> base;
public:
    sentence(const std::list<terminal*>& seq = { });
    sentence(const std::list<terminal_ptr>& seq);
    sentence(const std::initializer_list<terminal*>& seq);
    sentence(const std::initializer_list<terminal_ptr>& seq);
};

}

#endif /* GRUNE_SENTENCE_H */
