#define GRUNE_ASSERTION_TRAITS_NO_YAML
#include "unit_tests/tests.hpp"
#include "grune-yaml/grune-yaml.hpp"

#include "grune/non_terminal.hpp"
#include "grune/production.hpp"
#include "grune/symbol.hpp"
#include "grune/grammars/anbncn.hpp"
#include "grune/grammars/turtle.hpp"
#include "grune/grammars/tom_dick_and_harry.hpp"

#include <iostream>

using namespace grune;

class yaml_tests : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(yaml_tests);
    CPPUNIT_TEST(test_symbol);
    CPPUNIT_TEST(test_sequence); 
    CPPUNIT_TEST(test_sequence_list);
    CPPUNIT_TEST(test_production);
    CPPUNIT_TEST(test_grammar);
    CPPUNIT_TEST(test_simple_format);
    CPPUNIT_TEST_SUITE_END();

    template<class T>
    void assert_equal_end_to_end(T value)
    {
        T first_pass = 
            YAML::Load(YAML::Dump(YAML::Node(value))).as<T>();

        CPPUNIT_ASSERT_EQUAL(value, first_pass);

        T second_pass = 
            YAML::Load(YAML::Dump(YAML::Node(first_pass))).as<T>();

        CPPUNIT_ASSERT_EQUAL(value, second_pass);
    }

    template<class T>
    void assert_load_equal(const std::string& yaml_doc, T value)
    {
        YAML::Node node = YAML::Load(yaml_doc);
        CPPUNIT_ASSERT_EQUAL(value, YAML::Load(yaml_doc).as<T>());
    }

public:
    void test_symbol()
    {
        symbol empty;
        symbol asdf("asdf");
        non_terminal A("A");

        assert_equal_end_to_end(empty);
        assert_load_equal("{ is_terminal: yes, text: \"\" }", empty);

        assert_equal_end_to_end(asdf);
        assert_load_equal("{ is_terminal: yes, text: asdf }", asdf);

        assert_equal_end_to_end(A); 
        assert_load_equal("{ is_terminal: no, text: A }", A);
    }

    void test_sequence()
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

        assert_equal_end_to_end(empty);
        assert_equal_end_to_end(asdf);
        assert_equal_end_to_end(nts);
        assert_equal_end_to_end(mixed);
    }

    void test_sequence_list()
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
        
        assert_equal_end_to_end(empty);
        assert_equal_end_to_end(asdf);
        assert_equal_end_to_end(bits);
        assert_equal_end_to_end(nested_empty);
        assert_equal_end_to_end(mixed);
    }

    void test_production()
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

        assert_equal_end_to_end(empty);
        assert_equal_end_to_end(p1);
        assert_equal_end_to_end(p1_1);
        assert_equal_end_to_end(p1_2);
        assert_equal_end_to_end(p1_3);
        assert_equal_end_to_end(p2);
        assert_equal_end_to_end(p2_1);
        assert_equal_end_to_end(p2_2);
        assert_equal_end_to_end(p3);
        assert_equal_end_to_end(all);
    }

    void test_grammar()
    {
        auto anbncn = grune::grammars::anbncn();
        auto turtle = grune::grammars::cyclic_manhattan_turtle();
        auto tdh = grune::grammars::tom_dick_and_harry();

        assert_equal_end_to_end(anbncn);
        assert_equal_end_to_end(turtle);
        assert_equal_end_to_end(tdh);
    }

    void test_simple_format()
    {
        std::string yaml_doc = "[a, b, c, d]";
        sequence expected = { "a", "b", "c", "d" };
        
        assert_load_equal(yaml_doc, expected);
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION(yaml_tests);
