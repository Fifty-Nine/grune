#ifndef TESTS_H
#define TESTS_H

#include "grune/grune_fwd.hpp"
#include "grune/sentence_iterator.hpp"
#include "grune-yaml/grune-yaml.hpp"

#include <boost/test/unit_test.hpp>

#ifndef COVERITY_BUILD
#define GRUNE_TEST_SUITE(suite) BOOST_AUTO_TEST_SUITE(suite)
#define GRUNE_TEST_SUITE_END() BOOST_AUTO_TEST_SUITE_END()
#define GRUNE_TEST_CASE(suite, name) BOOST_AUTO_TEST_CASE(name)
#define GRUNE_TEST_CASE_END() 
#else
#include <coverity-test-separation.h>
#define GRUNE_TEST_SUITE(suite) BOOST_AUTO_TEST_SUITE(suite) 
#define GRUNE_TEST_SUITE_END() BOOST_AUTO_TEST_SUITE_END()

#define GRUNE_TEST_CASE(suite, name)\
    BOOST_AUTO_TEST_CASE(name) \
    { \
        COVERITY_TS_START_TEST(#suite "/" #name);

#define GRUNE_TEST_CASE_END() \
        COVERITY_TS_END_TEST(); \
    }
#endif /* COVERITY_BUILD */

#ifdef GRUNE_ASSERTION_TRAITS_NO_YAML
#define GRUNE_TO_STRING(x) grune::to_string(x)
#else
#define GRUNE_TO_STRING(x) YAML::Dump(YAML::Node(x));
#endif /* GRUNE_ASSERTION_TRAITS_NO_YAML */

#define GRUNE_ASSERTION_TRAITS_FWD(t) \
    namespace boost { namespace test_tools { \
        template<> \
        struct print_log_value<t> {\
            void operator()(std::ostream& os, const t&); \
        }; \
    } }

GRUNE_ASSERTION_TRAITS_FWD(grune::symbol);
GRUNE_ASSERTION_TRAITS_FWD(grune::non_terminal);
GRUNE_ASSERTION_TRAITS_FWD(grune::sequence);
GRUNE_ASSERTION_TRAITS_FWD(grune::sequence_list);
GRUNE_ASSERTION_TRAITS_FWD(grune::production);
GRUNE_ASSERTION_TRAITS_FWD(grune::production_list);
GRUNE_ASSERTION_TRAITS_FWD(grune::grammar);

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
