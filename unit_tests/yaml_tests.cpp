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
    bool equal_end_to_end(T value)
    {
        T first_pass = 
            YAML::Load(YAML::Dump(YAML::Node(value))).as<T>();
        T second_pass = 
            YAML::Load(YAML::Dump(YAML::Node(first_pass))).as<T>();
        return first_pass == value && second_pass == value;
    }

    template<class T>
    bool load_equal(const std::string& yaml_doc, T value)
    {
        YAML::Node node = YAML::Load(yaml_doc);
        return YAML::Load(yaml_doc).as<T>() == value;
    }

public:
    void test_symbol()
    {
        symbol empty;
        symbol asdf("asdf");
        non_terminal A("A");

        CPPUNIT_ASSERT(equal_end_to_end(empty));
        CPPUNIT_ASSERT(load_equal("{ is_terminal: yes, text: \"\" }", empty));

        CPPUNIT_ASSERT(equal_end_to_end(asdf));
        CPPUNIT_ASSERT(load_equal("{ is_terminal: yes, text: asdf }", asdf));

        CPPUNIT_ASSERT(equal_end_to_end(A)); 
        CPPUNIT_ASSERT(load_equal("{ is_terminal: no, text: A }", A));
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

        CPPUNIT_ASSERT(equal_end_to_end(empty));
        CPPUNIT_ASSERT(equal_end_to_end(asdf));
        CPPUNIT_ASSERT(equal_end_to_end(nts));
        CPPUNIT_ASSERT(equal_end_to_end(mixed));
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
        
        CPPUNIT_ASSERT(equal_end_to_end(empty));
        CPPUNIT_ASSERT(equal_end_to_end(asdf));
        CPPUNIT_ASSERT(equal_end_to_end(bits));
        CPPUNIT_ASSERT(equal_end_to_end(nested_empty));
        CPPUNIT_ASSERT(equal_end_to_end(mixed));
    }

    void test_production()
    {
        non_terminal A("A");
        non_terminal B("B");

        production empty;
        production p1 
        {
            A, 
            { 
                { "x" }, 
                { "y" },
                { "z" } 
            }
        };
        production p2
        {
            { A, B },
            { 
                { "x", "y", "z" }, 
                { "z", "y", "x" } 
            },
        };
        production p3
        {
            { B, A },
            { }
        };
        production_list all { p1, p2, p3 };

        CPPUNIT_ASSERT(equal_end_to_end(empty));
        CPPUNIT_ASSERT(equal_end_to_end(p1));
        CPPUNIT_ASSERT(equal_end_to_end(p2));
        CPPUNIT_ASSERT(equal_end_to_end(p3));
        CPPUNIT_ASSERT(equal_end_to_end(all));
    }

    void test_grammar()
    {
        auto anbncn = grune::grammars::anbncn();
        auto turtle = grune::grammars::cyclic_manhattan_turtle();
        auto tdh = grune::grammars::tom_dick_and_harry();

        CPPUNIT_ASSERT(equal_end_to_end(anbncn));
        CPPUNIT_ASSERT(equal_end_to_end(turtle));
        CPPUNIT_ASSERT(equal_end_to_end(tdh));
    }

    void test_simple_format()
    {
        std::string yaml_doc = "[a, b, c, d]";
        sequence expected = { "a", "b", "c", "d" };
        
        CPPUNIT_ASSERT(load_equal(yaml_doc, expected));
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION(yaml_tests);
