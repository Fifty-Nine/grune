#ifndef TESTS_H
#define TESTS_H

#include <boost/test/unit_test.hpp>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TextTestRunner.h>

#include "grune/grune_fwd.hpp"
#include "grune/sentence_iterator.hpp"
#include "grune-yaml/grune-yaml.hpp"

template<class T>
struct grune_assertion_traits
{
    static bool equal(const T& x, const T& y)
    {
        return x == y;
    }

    static std::string toString(const T& x)
    {
#ifndef GRUNE_ASSERTION_TRAITS_NO_YAML
        return YAML::Dump(YAML::Node(x));
#else /* GRUNE_ASSERTION_TRAITS_NO_YAML */
        return grune::to_string(x);
#endif
    }

};

#define GRUNE_ASSERTION_TRAITS(t) \
    namespace CppUnit { \
    template<> \
    struct assertion_traits<t> : \
        public grune_assertion_traits<t> \
    { }; }\
    namespace boost { namespace test_tools { \
    template<> \
    struct print_log_value<t> { \
        template<class T=void> \
        void operator()(std::ostream& os, const t& v) { \
            grune_assertion_traits<t>::toString(v); \
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

namespace CppUnit {
template<>
struct assertion_traits<grune::sentence_iterator>
{
    typedef grune::sentence_iterator T;
    static bool equal(const T& x, const T& y) { return x == y; }
    static std::string toString(const T& x)
    {
        using namespace grune;
        if (x != sentence_iterator())
        {
            return assertion_traits<sequence>::toString(*x);
        }
        return "<end>";
    }
};

}

namespace boost { 
namespace test_tools { 
    template<>
    struct print_log_value<grune::sentence_iterator> 
    {
        void operator()(std::ostream& os, const grune::sentence_iterator& v) 
        {
            os << CppUnit::assertion_traits<grune::sentence_iterator>::toString(v);
        }
    };
} 
}

#endif /* TESTS_H */
