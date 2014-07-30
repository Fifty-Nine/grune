#ifndef GRUNE_GENERATE_H
#define GRUNE_GENERATE_H

#include "grune/grune_fwd.hpp"

namespace grune
{

/* 
 * Generate count sentences from the given grammar using
 * a breadth first algorithm. If count is negative, generate
 * all the sentences.
 */
sequence_list generate(const grammar& g, int count = -1);

}

#endif /* GRUNE_GENERATE_H */
