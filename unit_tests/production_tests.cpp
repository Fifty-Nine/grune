#include "unit_tests/tests.hpp"
#include "grune/all.hpp"

using namespace grune;

BOOST_AUTO_TEST_SUITE(production_test)

BOOST_AUTO_TEST_CASE(initialized_test)
{
    non_terminal nt("S");
    production uninit;
    production init { nt, { } };

    BOOST_CHECK(!uninit.initialized());
    BOOST_CHECK(init.initialized());
}

BOOST_AUTO_TEST_CASE(to_string_test)
{
    non_terminal left("left");
    non_terminal right("right");
    symbol l1("1");
    symbol l2("2");

    production p { left, { right, l1, l2 } };

    std::string expected = "left = right, \"1\", \"2\"";
    BOOST_CHECK_EQUAL(expected, p.to_string());

    production p2_1 { right, { l1, l2 } };
    production p2_2 { right, { left, left } };
    production_list p2 { p2_1, p2_2 };

    expected = "right = \"1\", \"2\"";
    BOOST_CHECK_EQUAL(expected, to_string(p2_1));

    expected = "right = left, left";
    BOOST_CHECK_EQUAL(expected, to_string(p2_2));

    expected = "right = \"1\", \"2\" | left, left;\n";
    BOOST_CHECK_EQUAL(expected, to_string(p2));

    production p3_1 { { left, right }, { l1, right } };
    production p3_2 { { left, right }, { left, l2 } };
    production_list p3 { p3_1, p3_2 };

    expected = "left, right = \"1\", right";
    BOOST_CHECK_EQUAL(expected, to_string(p3_1));

    expected = "left, right = left, \"2\"";
    BOOST_CHECK_EQUAL(expected, to_string(p3_2));

    expected = "left, right = \"1\", right | left, \"2\";\n";
    BOOST_CHECK_EQUAL(expected, to_string(p3));

    production empty_rhs(left, { });
    expected = "left = \"\"";
    BOOST_CHECK_EQUAL(expected, to_string(empty_rhs));
}

BOOST_AUTO_TEST_CASE(apply_test)
{
    non_terminal A("A");
    non_terminal B("B");
    non_terminal C("C");

    production p1_1 { A, { "b", "c" } };
    production p1_2 { A, { "d" } };
    production_list p1 { p1_1, p1_2 };

    BOOST_CHECK(apply(p1_1, {}).empty());
    BOOST_CHECK(apply(p1_2, {}).empty());
    BOOST_CHECK(apply(p1, {}).empty());

    sequence_list result = apply(p1, {"x", A, "y"});
    BOOST_CHECK_EQUAL((int)result.size(), 2);

    sequence_list expected = 
    {
        { "x", "b", "c", "y" },
        { "x", "d", "y" }
    };
    BOOST_CHECK_EQUAL(result, expected);
}
BOOST_AUTO_TEST_SUITE_END()
