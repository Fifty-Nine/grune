#ifndef GRUNE_GRAMMARS_ANBNCN_H
#define GRUNE_GRAMMARS_ANBNCN_H

#include "grune/grammar.hpp"

namespace grune
{
namespace grammars
{

/*
 * Get an instance of the a^nb^nc^n grammar, a traditional example
 * of a context-sensitive grammar. The sentences produced by the
 * grammar look like:
 *
 * abc
 * aabbcc
 * aaabbbcc
 * ...
 *
 */
grammar anbncn();

}
}

#endif /* GRUNE_GRAMMARS_ANBNCN_H */
