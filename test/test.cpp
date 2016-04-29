// Jimmy Von Holle
// CS 372
// Simple test suite using catch
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/a4.h"

TEST_CASE("Testing Levels"){
    Level test("test.map");
    Level test1("test1.map");

    SECTION("Checking Description loading"){
        REQUIRE(test.get_description() == "This is the test level, you can move forward, back, left, or right. 3/4 end in death.");
        REQUIRE(test1.get_description() == "This is the test 2 map. Congratulations on not being dead. You can only go back from here.");
    }SECTION("Checking Next Values"){
        REQUIRE(test.get_next()["forward"] != nullptr);
        REQUIRE(test.get_next()["back"] != nullptr);
        REQUIRE(test.get_next()["left"] != nullptr);
        REQUIRE(test.get_next()["right"] != nullptr);

        REQUIRE(test1.get_next()["back"] != nullptr);
    }

}
