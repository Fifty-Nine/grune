#include "unit_tests/tests.hpp"
#include "grune-json/grune-json.hpp"

#include "grune/non_terminal.hpp"
#include "grune/production.hpp"
#include "grune/symbol.hpp"
#include "grune/grammars/anbncn.hpp"
#include "grune/grammars/turtle.hpp"
#include "grune/grammars/tom_dick_and_harry.hpp"

#include <iostream>

using namespace grune;

namespace
{

#define ASSERT_EQUAL_END_TO_END(value) \
    do { \
        std::string err; \
        auto first_pass = \
            json11::Json::parse( \
                json11::Json(value).dump(), \
                err\
            ).as<decltype(value)>(); \
        BOOST_CHECK_EQUAL(err, std::string()); \
        BOOST_CHECK_EQUAL(first_pass, value); \
        auto second_pass = \
            json11::Json::parse( \
                json11::Json(first_pass).dump(), \
                err\
            ).as<decltype(value)>(); \
        BOOST_CHECK_EQUAL(err, std::string()); \
        BOOST_CHECK_EQUAL(second_pass, value); \
    } while (0)

#define ASSERT_LOAD_EQUAL(document, value) \
    do { \
        std::string err; \
        auto new_value = \
            json11::Json::parse(document, err).as<decltype(value)>(); \
        BOOST_CHECK_EQUAL(err, std::string()); \
        BOOST_CHECK_EQUAL(value, new_value); \
    } while (0)

}

BOOST_AUTO_TEST_SUITE(json_tests)

BOOST_AUTO_TEST_CASE(symbol_test)
{
    symbol empty;
    symbol asdf("asdf");
    non_terminal A("A");

    ASSERT_EQUAL_END_TO_END(empty);
    ASSERT_LOAD_EQUAL("{ \"is_terminal\": true, \"text\": \"\" }", empty);

    ASSERT_EQUAL_END_TO_END(asdf);
    ASSERT_LOAD_EQUAL("{ \"is_terminal\": true, \"text\": \"asdf\" }", asdf);

    ASSERT_EQUAL_END_TO_END(A); 
    ASSERT_LOAD_EQUAL("{ \"is_terminal\": false, \"text\": \"A\" }", A);
}

BOOST_AUTO_TEST_CASE(sequence_test)
{
    sequence empty { };
    sequence asdf { "a", "s", "d", "f" };
    sequence nts 
    { 
        non_terminal("A"), 
        non_terminal("B"), 
        non_terminal("C"),
    };

    sequence mixed
    {
        "(", non_terminal("expr"), ")"
    };

    ASSERT_EQUAL_END_TO_END(empty);
    ASSERT_EQUAL_END_TO_END(asdf);
    ASSERT_EQUAL_END_TO_END(nts);
    ASSERT_EQUAL_END_TO_END(mixed);
}

BOOST_AUTO_TEST_CASE(sequence_list_test)
{
    sequence_list empty { };
    sequence_list asdf { { "a" }, { "s" }, { "d" }, { "f" } };
    sequence_list bits 
    { 
        { 0, 0 },
        { 0, 1 },
        { 1, 0 },
        { 1, 1 },
    };
    sequence_list nested_empty 
    {
        { },
        { },
        { },
    };
    sequence_list mixed
    {
        { "a", "s" },
        { non_terminal("D"), non_terminal("F") },
        { },
        { "q", non_terminal("W"), "erty" },
    };
    
    ASSERT_EQUAL_END_TO_END(empty);
    ASSERT_EQUAL_END_TO_END(asdf);
    ASSERT_EQUAL_END_TO_END(bits);
    ASSERT_EQUAL_END_TO_END(nested_empty);
    ASSERT_EQUAL_END_TO_END(mixed);
}

BOOST_AUTO_TEST_CASE(production_test)
{
    non_terminal A("A");
    non_terminal B("B");

    production empty;
    production p1_1 { A, { "x" } };
    production p1_2 { A, { "y" } };
    production p1_3 { A, { "z" } };
    production_list p1 { p1_1, p1_2, p1_3 };
    production p2_1 { { A, B }, { "x", "y", "z" } };
    production p2_2 { { A, B }, { "z", "y", "x" } };
    production_list p2 { p2_1, p2_2 };
    production p3 { { B, A }, { } };
    production_list all { p1_1, p1_2, p1_3, p2_1, p2_2, p3 };

    ASSERT_EQUAL_END_TO_END(empty);
    ASSERT_EQUAL_END_TO_END(p1);
    ASSERT_EQUAL_END_TO_END(p1_1);
    ASSERT_EQUAL_END_TO_END(p1_2);
    ASSERT_EQUAL_END_TO_END(p1_3);
    ASSERT_EQUAL_END_TO_END(p2);
    ASSERT_EQUAL_END_TO_END(p2_1);
    ASSERT_EQUAL_END_TO_END(p2_2);
    ASSERT_EQUAL_END_TO_END(p3);
    ASSERT_EQUAL_END_TO_END(all);
}

BOOST_AUTO_TEST_CASE(grammar_test)
{
    auto anbncn = grune::grammars::anbncn();
    auto turtle = grune::grammars::cyclic_manhattan_turtle();
    auto tdh = grune::grammars::tom_dick_and_harry();

    ASSERT_EQUAL_END_TO_END(anbncn);
    ASSERT_EQUAL_END_TO_END(turtle);
    ASSERT_EQUAL_END_TO_END(tdh);
}

BOOST_AUTO_TEST_CASE(simple_format_test)
{
    std::string json_doc = "[a, b, c, d]";
    sequence expected = { "a", "b", "c", "d" };
    
    ASSERT_LOAD_EQUAL(json_doc, expected);
}

BOOST_AUTO_TEST_CASE(simple_nonterms)
{
    symbol t("_t");
    non_terminal nt("_nt");
    symbol empty_term("");
    non_terminal empty_nonterm("");

    ASSERT_EQUAL_END_TO_END(t);
    ASSERT_EQUAL_END_TO_END(nt);
    ASSERT_EQUAL_END_TO_END(empty_term);
    ASSERT_EQUAL_END_TO_END(empty_nonterm);

    ASSERT_LOAD_EQUAL("{ \"is_terminal\": true, \"text\": \"_t\" }", t);
    ASSERT_LOAD_EQUAL("{ \"is_terminal\": false, \"text\": \"_nt\" }", nt);
    ASSERT_LOAD_EQUAL("{ \"is_terminal\": true, \"text\": \"\" }", empty_term);
    ASSERT_LOAD_EQUAL("{ \"is_terminal\": false, \"text\": \"\" }", empty_nonterm);
    
    ASSERT_LOAD_EQUAL("\\_t", t);
    ASSERT_LOAD_EQUAL("__nt", nt);
    ASSERT_LOAD_EQUAL("\"\"", empty_term);
    ASSERT_LOAD_EQUAL("_", empty_nonterm);
}

BOOST_AUTO_TEST_CASE(short_production)
{
    non_terminal A("A");
    symbol a("a");

    production p
    {
        A, { a }
    };

    ASSERT_EQUAL_END_TO_END(p);
    ASSERT_LOAD_EQUAL("{ \"lhs\": \"_A\", \"rhs\": \"a\" }", p);
}

BOOST_AUTO_TEST_SUITE_END()
