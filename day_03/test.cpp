#include <catch2/catch_all.hpp>
#include "exercise_1.hpp"
#include "exercise_2.hpp"
#include <fstream>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// Part 1
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

TEST_CASE("find num indexes from position", "[p1]") {
  std::string s{"7.102.7"};
  //               2p4
  REQUIRE(p1::getNumIndexes(s, 3) == std::pair<std::size_t, std::size_t>{2, 4});
}

TEST_CASE("find num indexes from position all", "[p1]") {
  std::string s{"7710277"};
  //             0  p  6
  REQUIRE(p1::getNumIndexes(s, 3) == std::pair<std::size_t, std::size_t>{0, 6});
}

TEST_CASE("find num indexes from position start", "[p1]") {
  std::string s{"1234..."};
  //             0 pr  
  REQUIRE(p1::getNumIndexes(s, 2) == std::pair<std::size_t, std::size_t>{0, 3});
}

TEST_CASE("example line number from 3", "[p1]") {
  REQUIRE(p1::getLineNumber("..34..#.", 2).first == 34);
  //                       2
}

TEST_CASE("example line number from 1", "[p1]") {
  REQUIRE(p1::getLineNumber(".134..#.", 1).first == 134);
  //                      1
}

TEST_CASE("example line number reversed from 4", "[p1]") {
  REQUIRE(p1::getLineNumber("..34..", 3).first == 34);
  //                        3
}

TEST_CASE("example line number reversed from 3", "[p1]") {
  auto [num, first] = p1::getLineNumber(".134..#.", 3);
  //                                    3
  REQUIRE((num == 134 && first == 1));
}

TEST_CASE("example line number reversed from 2 middle", "[p1]") {
  auto [num, first] = p1::getLineNumber(".134..#.", 2);
  //                                   2
  REQUIRE((num == 134 && first == 1));
}

TEST_CASE("example count all", "[p1]") {
  REQUIRE(p1::countRatios({
      {"467..114.."},
      {"...*......"},
      {"..35..633."},
      {"......#..."},
      {"617*......"},
      {".....+.58."},
      {"..592....."},
      {"......755."},
      {"...$.*...."},
      {".664.598.."},
        }) == 4361);
}

TEST_CASE("my count all", "[p1]") {
  REQUIRE(p1::countRatios({
      {"......"},
      {"......"}}) == 0);
}

TEST_CASE("my count all 1", "[p1]") {
  REQUIRE(p1::countRatios({
      {"..*..."},
      {".123.."}}) == 123);
}

TEST_CASE("my count all 2", "[p1]") {
  REQUIRE(p1::countRatios({
      {"..*..*"},
      {".123.1"}}) == 124);
}

TEST_CASE("my count all 3", "[p1]") {
  REQUIRE(p1::countRatios({
      {"..*..*."},
      {".123.12"}}) == 135);
}

TEST_CASE("my count all 4", "[p1]") {
  REQUIRE(p1::countRatios({
      {"..*..*.."},
      {".123.122"}}) == 123 + 122);
}

TEST_CASE("my count all 5", "[p1]") {
  REQUIRE(p1::countRatios({
      {"..*..*..."},
      {".123..123"}}) == 123 + 123);
}

TEST_CASE("empty", "[p1]") {
  REQUIRE(p1::countRatios({
      {".........."},
      {".........."},
      {".........."},
      {".........."},
      {".........."},
      {".........."},
      {".........."},
      {".........."},
        }) == 0);
}
TEST_CASE("given input1", "[p1]") {

  std::ifstream file{"input.txt"};
  std::vector<std::string> grid;
  for(std::string line{}; std::getline(file, line);) grid.push_back(line);

  REQUIRE(p1::countRatios(grid) == 531561);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// Part 2
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

TEST_CASE("example count all", "[p2]") {
  REQUIRE(p2::countRatios({
      {"467..114.."},
      {"...*......"},
      {"..35..633."},
      {"......#..."},
      {"617*......"},
      {".....+.58."},
      {"..592....."},
      {"......755."},
      {"...$.*...."},
      {".664.598.."},
        }) == 467835);
}
TEST_CASE("example gear", "[p2]") {
  REQUIRE(p2::countRatios({
      {".*...*...."},
      {"2.2..1...."},
        }) == 4);
}

int main(int argc, char *argv[]) {
  return Catch::Session().run(argc, argv);
}
