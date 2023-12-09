#include <catch2/catch_all.hpp>
#include "exercise_1.hpp"
#include "exercise_2.hpp"
#include <fstream>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// Part 1
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

TEST_CASE("game line example 1", "[p1]") {
  auto s = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green";
  auto gp = p1::isGamePossible(s);
  REQUIRE(gp.second == true);
  REQUIRE(gp.first == 1);
}

TEST_CASE("game line example 2", "[p1]") {
  auto s = "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue";
  auto gp = p1::isGamePossible(s);
  REQUIRE(gp.second == true);
  REQUIRE(gp.first == 2);
}

TEST_CASE("game line example 3", "[p1]") {
  auto s = "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red";
  auto gp = p1::isGamePossible(s);
  REQUIRE(gp.second == false);
  REQUIRE(gp.first == 3);
}

TEST_CASE("game line example 4", "[p1]") {
  auto s = "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red";
  auto gp = p1::isGamePossible(s);
  REQUIRE(gp.second == false);
  REQUIRE(gp.first == 4);
}

TEST_CASE("game line example 5", "[p1]") {
  auto s = "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green";
  auto gp = p1::isGamePossible(s);
  REQUIRE(gp.second == true);
  REQUIRE(gp.first == 5);
}

TEST_CASE("given input", "[p1]") {
  REQUIRE(p1::countValidGames("input.txt") == 2727);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// Part 2
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

TEST_CASE("game line example 1", "[p2]") {
  auto s = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green";
  auto p = p2::powerOfGame(s);
  REQUIRE(p == 48);
}

TEST_CASE("game line example 2", "[p2]") {
  auto s = "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue";
  auto p = p2::powerOfGame(s);
  REQUIRE(p == 12);
}

TEST_CASE("game line example 3", "[p2]") {
  auto s = "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red";
  auto p = p2::powerOfGame(s);
  REQUIRE(p == 1560);
}

TEST_CASE("game line example 4", "[p2]") {
  auto s = "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red";
  auto p = p2::powerOfGame(s);
  REQUIRE(p == 630);
}

TEST_CASE("game line example 5", "[p2]") {
  auto s = "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green";
  auto p = p2::powerOfGame(s);
  REQUIRE(p == 36);
}

int main(int argc, char *argv[]) {
  return Catch::Session().run(argc, argv);
}
