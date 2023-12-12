#include <catch2/catch_all.hpp>
#include "exercise_1.hpp"
#include "exercise_2.hpp"
#include <fstream>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// Part 1
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
TEST_CASE("example 1") {
  auto s = "Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53";
  REQUIRE(p1::getCardPoints(s) == 8);
}

TEST_CASE("example 2") {
  auto s = "Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19";
  REQUIRE(p1::getCardPoints(s) == 2);
}

TEST_CASE("example 3") {
  auto s = "Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1";
  REQUIRE(p1::getCardPoints(s) == 2);
}

TEST_CASE("example 4") {
  auto s = "Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83";
  REQUIRE(p1::getCardPoints(s) == 1);
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// Part 2
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 



int main(int argc, char *argv[]) {
  return Catch::Session().run(argc, argv);
}
