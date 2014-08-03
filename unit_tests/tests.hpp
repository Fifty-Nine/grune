#ifndef TESTS_H
#define TESTS_H

#include "grune/grune_fwd.hpp"
#include "grune/sentence_iterator.hpp"
#include "grune-yaml/grune-yaml.hpp"

#include <boost/test/unit_test.hpp>

#ifdef GRUNE_ASSERTION_TRAITS_NO_YAML
#define GRUNE_TO_STRING(x) grune::to_string(x)
#else
#define GRUNE_TO_STRING(x) YAML::Dump(YAML::Node(x));
#endif /* GRUNE_ASSERTION_TRAITS_NO_YAML */

#define GRUNE_ASSERTION_TRAITS(t) \
    namespace boost { namespace test_tools { \
    template<> \
    struct print_log_value<t> { \
        template<class T=void> \
        void operator()(std::ostream& os, const t& v) { \
            os << GRUNE_TO_STRING(v); \
        } \
    }; \
    } }

GRUNE_ASSERTION_TRAITS(grune::symbol);
GRUNE_ASSERTION_TRAITS(grune::non_terminal);
GRUNE_ASSERTION_TRAITS(grune::sequence);
GRUNE_ASSERTION_TRAITS(grune::sequence_list);
GRUNE_ASSERTION_TRAITS(grune::production);
GRUNE_ASSERTION_TRAITS(grune::production_list);
GRUNE_ASSERTION_TRAITS(grune::grammar);

namespace boost { 
namespace test_tools { 
    template<>
    struct print_log_value<grune::sentence_iterator> 
    {
        void operator()(std::ostream& os, const grune::sentence_iterator& v) 
        {
            auto r = 
                (v == grune::sentence_iterator()) ? 
                "<end>" : grune::to_string(*v);
            os << r;
        }
    };
} 
}

#endif /* TESTS_H */
