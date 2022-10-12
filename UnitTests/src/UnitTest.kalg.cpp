#include "kalg.h"

// tell catch to define main
#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

using namespace kalg;

TEST_CASE("size", "[kalg]") {
    Graph g(5);
    REQUIRE(g.size() == 5);
}

TEST_CASE("addEdge", "[kalg]") { 

    constexpr int GRAPH_SIZE = 8;
    Graph g(GRAPH_SIZE);

    // check adding nodes
    REQUIRE(g.addEdge(4, 2));
    REQUIRE(g.addEdge(3, 1));
    REQUIRE(g.addEdge(4, 1));
    REQUIRE(g.addEdge(2, 3));

    // check adding out of range
    REQUIRE(!g.addEdge(GRAPH_SIZE+1, 0));
    REQUIRE(!g.addEdge(1, GRAPH_SIZE+1));

    // check adding duplicate node
    REQUIRE(!g.addEdge(3, 1));

}

TEST_CASE("sort", "[kalg]") {


    constexpr int GRAPH_SIZE = 6;
    Graph g(GRAPH_SIZE);

    // add some nodes
    REQUIRE(g.addEdge(4, 2));
    REQUIRE(g.addEdge(3, 1));
    REQUIRE(g.addEdge(4, 1));
    REQUIRE(g.addEdge(2, 3));

    SECTION("normal sort") {
        auto result = g.sort();

        REQUIRE(result.size() == g.size());

        REQUIRE(result[0] == 0);
        REQUIRE(result[1] == 4);
        REQUIRE(result[2] == 5);
        REQUIRE(result[3] == 2);
        REQUIRE(result[4] == 3);
        REQUIRE(result[5] == 1);
    }

    SECTION("sort with loop") {


        REQUIRE(g.addEdge(1, 2));

        auto result = g.sort();

        // make sure results don't include the loop
        REQUIRE(result.size() != g.size());
        REQUIRE(result.size() == 3);
        REQUIRE(g.size() == GRAPH_SIZE);

        // only nodes without loop
        REQUIRE(result[0] == 0);
        REQUIRE(result[1] == 4);
        REQUIRE(result[2] == 5);
    }
}



