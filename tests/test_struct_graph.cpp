#include <doctest.h>

#include <iostream>

#include "../src/vlib/edge.h"
#include "../src/weighted_struct_digraph.h"
#include "TestAirport.h"

TEST_CASE("A1: Test Struct Graph (Explicit Construction)") {
    // As well as this one using vectors
    REQUIRE_NOTHROW(
        WeightedStructDigraph<TestAirport> sdg2(std::vector<TestAirport>{
            {1, 1.0, 1.0},
            {2, 2.0, 2.0},
            {3, 3.0, 3.0},
            {4, 4.0, 4.0},
            {5, 5.0, 5.0},
        }));

    WeightedStructDigraph<TestAirport> sdg(std::vector<TestAirport>{
        {1, 1.0, 1.0},
        {2, 2.0, 2.0},
        {3, 3.0, 3.0},
        {4, 4.0, 4.0},
        {5, 5.0, 5.0},
    });
    // the graph should have 5 vertices
    CHECK(sdg.get_graph()->V() == 5);

    // the first airport should be this one
    CHECK(sdg.name_of(0) == TestAirport{1, 1.0, 1.0});

    // It should contain this airport
    CHECK(sdg.contains(TestAirport{5, 5.0, 2.0}));

    // It should not contain this airport
    CHECK(!sdg.contains(TestAirport{6, 5.0, 2.0}));

    // adding Edges to the graph should not throw
    REQUIRE_NOTHROW(sdg.add_edge(sdg.name_of(1), sdg.name_of(2), 1.0));
}