#ifndef GRUNE_GRAMMARS_TURTLE
#define GRUNE_GRAMMARS_TURTLE

#include "grune/all.hpp"

namespace grune
{
namespace grammars
{

/*
 * A recursively enumerable (type-0) grammar that represents the movement 
 * of a "manhattan turtle" which moves one block at a time heading in a 
 * cardinal direction. This grammar produces all the possible routes that
 * return to the starting point.
 */
grammar cyclic_manhattan_turtle();

}
}

#endif /* GRUNE_GRAMMARS_TURTLE */
