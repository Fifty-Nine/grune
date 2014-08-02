#include "unit_tests/tests.hpp"
#include "grune-yaml/grune-yaml.hpp"

#include "grune/non_terminal.hpp"
#include "grune/production.hpp"
#include "grune/symbol.hpp"

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

    template<class T>
    void write_file(const std::string& name, const T& value)
    {
        std::ofstream out("results/" + name);
        out << YAML::Node(value) << std::endl;
    }

public:
    void test_symbol()
    {
        symbol empty;
        symbol asdf("asdf");
        non_terminal A("A");

        write_file("empty.sym", empty);
        write_file("asdf.sym", asdf);
        write_file("A.sym", A);

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

        write_file("empty.seq", empty); 
        write_file("asdf.seq", asdf);
        write_file("nts.seq", nts);
        write_file("mixed.seq", mixed);

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
        
        write_file("empty.seqs", empty);
        write_file("asdf.seqs", asdf);
        write_file("bits.seqs", bits);
        write_file("nested_empty.seqs", nested_empty);
        write_file("mixed.seqs", mixed);

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

        write_file("empty.prod", empty);
        write_file("p1.prod", p1);
        write_file("p2.prod", p2);
        write_file("p3.prod", p3);
        write_file("all.plist", all);

        CPPUNIT_ASSERT(equal_end_to_end(empty));
        CPPUNIT_ASSERT(equal_end_to_end(p1));
        CPPUNIT_ASSERT(equal_end_to_end(p2));
        CPPUNIT_ASSERT(equal_end_to_end(p3));
        CPPUNIT_ASSERT(equal_end_to_end(all));
    }

    void test_grammar()
    {
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION(yaml_tests);
