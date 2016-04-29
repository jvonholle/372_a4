// Jimmy Von Holle
// CS 372
// Simple test suite using catch
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/a4.h"
#include <string>

TEST_CASE("Testing Levels"){
    Level test("test.map");
    Level test1("test1.map");

    SECTION("Checking Description loading"){
        REQUIRE(test.get_description() == "This is the test level, you can move forward, back, left, or right. 3/4 end in death. ");
        REQUIRE(test1.get_description() == "This is the test 2 map. Congratulations on not being dead. You can only go back from here. ");
    }SECTION("Checking Next Values"){
        REQUIRE(test.get_next()["forward"] != nullptr);
        REQUIRE(test.get_next()["back"] != nullptr);
        REQUIRE(test.get_next()["left"] != nullptr);
        REQUIRE(test.get_next()["right"] != nullptr);

        REQUIRE(test1.get_next()["back"] != nullptr);
    }

}
TEST_CASE("Testing Action"){
    Level test_lev("test.map");
    Level test_lev1("start.map");
    Action test("test.map");
    Action test1;
    
    SECTION("Checking current"){
        REQUIRE(test.get_current()->get_description() == test_lev.get_description());
        REQUIRE(test1.get_current()->get_description() == test_lev1.get_description());
    }
}
TEST_CASE("Testing Handlers"){
    
}