#ifndef GRUNE_GRAMMARS_TOM_DICK_HARRY_H
#define GRUNE_GRAMMARS_TOM_DICK_HARRY_H

#include "grune/grammar.hpp"

namespace grune
{

namespace grammars
{

/* 
 * A context-free grammar that generates sentences 
 * consisting of a list of people named Tom, Dick and Harry.
 * Examples:
 * tom, dick and harry
 * dick, tom, harry, tom, tom, tom, dick and harry
 * dick and harry
 */
grammar tom_dick_and_harry();

}
}

#endif /* GRUNE_GRAMMARS_TOM_DICK_HARRY_H */
