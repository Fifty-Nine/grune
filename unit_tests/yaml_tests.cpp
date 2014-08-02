#include "unit_tests/tests.hpp"
#include "grune-yaml/grune-yaml.hpp"

#include "grune/non_terminal.hpp"
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
    }

    void test_sequence_list()
    {
    }

    void test_production()
    {
    }

    void test_grammar()
    {
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION(yaml_tests);
