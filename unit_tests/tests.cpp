#include "unit_tests/tests.hpp"
#include "grune/all.hpp"

#define GRUNE_ASSERTION_TRAITS(t) \
    void boost::test_tools::print_log_value<t>::operator()( \
        std::ostream& os, const t& v) \
    { \
        os << GRUNE_TO_STRING(v); \
    }

GRUNE_ASSERTION_TRAITS(grune::symbol);
GRUNE_ASSERTION_TRAITS(grune::non_terminal);
GRUNE_ASSERTION_TRAITS(grune::sequence);
GRUNE_ASSERTION_TRAITS(grune::sequence_list);
GRUNE_ASSERTION_TRAITS(grune::production);
GRUNE_ASSERTION_TRAITS(grune::production_list);
GRUNE_ASSERTION_TRAITS(grune::grammar);
