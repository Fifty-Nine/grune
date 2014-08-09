#include "grune/grammar.hpp"
#include "grune/non_terminal.hpp"
#include "grune/production.hpp"
#include "grune/symbol.hpp"

#include <type_traits>

using namespace grune;

#ifndef NO_CHECKING
#define ASSERT_TRAIT(trait, type) \
    static_assert( \
        std::trait<type>::value, \
        "Constraint not satisfied for type " #type ": " #trait \
    );
#define ASSERT_NO_TRAIT(trait, type) \
    static_assert( \
        !std::trait<type>::value, \
        "Constraint not satisfied for type " #type ": !" #trait \
    );
#else
#define ASSERT_TRAIT(trait, type)
#define ASSERT_NO_TRAIT(trait, type)
#endif

ASSERT_NO_TRAIT(is_abstract, symbol);
ASSERT_NO_TRAIT(is_abstract, non_terminal);
ASSERT_NO_TRAIT(is_abstract, production);
ASSERT_NO_TRAIT(is_abstract, grammar);

ASSERT_TRAIT(is_default_constructible, symbol);
ASSERT_TRAIT(is_default_constructible, non_terminal);
ASSERT_TRAIT(is_default_constructible, production);
ASSERT_TRAIT(is_default_constructible, grammar);

ASSERT_TRAIT(is_copy_constructible, symbol);
ASSERT_TRAIT(is_copy_constructible, non_terminal);
ASSERT_TRAIT(is_copy_constructible, production);
ASSERT_TRAIT(is_copy_constructible, grammar);

ASSERT_TRAIT(is_move_constructible, symbol);
ASSERT_TRAIT(is_nothrow_move_constructible, non_terminal);
ASSERT_TRAIT(is_nothrow_move_constructible, production);
ASSERT_TRAIT(is_move_constructible, grammar);

ASSERT_TRAIT(is_nothrow_destructible, symbol);
ASSERT_TRAIT(is_nothrow_destructible, non_terminal);
ASSERT_TRAIT(is_nothrow_destructible, production);
ASSERT_TRAIT(is_nothrow_destructible, grammar);

ASSERT_TRAIT(is_copy_assignable, symbol);
ASSERT_TRAIT(is_copy_assignable, non_terminal);
ASSERT_TRAIT(is_copy_assignable, production);
ASSERT_TRAIT(is_copy_assignable, grammar);

ASSERT_TRAIT(is_nothrow_move_assignable, symbol);
ASSERT_TRAIT(is_move_assignable, non_terminal);
ASSERT_TRAIT(is_move_assignable, production);
ASSERT_TRAIT(is_move_assignable, grammar);

ASSERT_NO_TRAIT(is_polymorphic, symbol);
ASSERT_NO_TRAIT(is_polymorphic, non_terminal);
ASSERT_NO_TRAIT(is_polymorphic, production);
ASSERT_NO_TRAIT(is_polymorphic, grammar);
