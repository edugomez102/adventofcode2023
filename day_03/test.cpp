#include <catch2/catch_all.hpp>
#include "exercise_1.hpp"
#include "exercise_2.hpp"
#include <fstream>

TEST_CASE("find num indexes from position") {
  std::string s{"7.102.7"};
  //               2p4
  REQUIRE(getNumIndexes(s, 3) == std::pair<std::size_t, std::size_t>{2, 4});
}

TEST_CASE("find num indexes from position all") {
  std::string s{"7710277"};
  //             0  p  6
  REQUIRE(getNumIndexes(s, 3) == std::pair<std::size_t, std::size_t>{0, 6});
}

TEST_CASE("find num indexes from position start") {
  std::string s{"1234..."};
  //             0 pr  
  REQUIRE(getNumIndexes(s, 2) == std::pair<std::size_t, std::size_t>{0, 3});
}

TEST_CASE("example line number from 3") {
  REQUIRE(getLineNumber("..34..#.", 2).first == 34);
  //                       2
}

TEST_CASE("example line number from 1") {
  REQUIRE(getLineNumber(".134..#.", 1).first == 134);
  //                      1
}

TEST_CASE("example line number reversed from 4") {
  REQUIRE(getLineNumber("..34..", 3).first == 34);
  //                        3
}

TEST_CASE("example line number reversed from 3") {
  auto [num, first] = getLineNumber(".134..#.", 3);
  //                                    3
  REQUIRE((num == 134 && first == 1));
}

TEST_CASE("example line number reversed from 2 middle") {
  auto [num, first] = getLineNumber(".134..#.", 2);
  //                                   2
  REQUIRE((num == 134 && first == 1));
}

TEST_CASE("example count all") {
  REQUIRE(countRatios({
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

TEST_CASE("my count all") {
  REQUIRE(countRatios({
      {"......"},
      {"......"}}) == 0);
}

TEST_CASE("my count all 1") {
  REQUIRE(countRatios({
      {"..*..."},
      {".123.."}}) == 123);
}

TEST_CASE("my count all 2") {
  REQUIRE(countRatios({
      {"..*..*"},
      {".123.1"}}) == 124);
}

TEST_CASE("my count all 3") {
  REQUIRE(countRatios({
      {"..*..*."},
      {".123.12"}}) == 135);
}

TEST_CASE("my count all 4") {
  REQUIRE(countRatios({
      {"..*..*.."},
      {".123.122"}}) == 123 + 122);
}

TEST_CASE("my count all 5") {
  REQUIRE(countRatios({
      {"..*..*..."},
      {".123..123"}}) == 123 + 123);
}

TEST_CASE("jkj") {
  REQUIRE(countRatios({
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
TEST_CASE("input") {

  std::ifstream file{"input.txt", std::ios::binary};
  std::string input{std::istreambuf_iterator<char>(file),
                  std::istreambuf_iterator<char>()};

  std::vector<std::string> grid{};
  std::string::value_type* p = &(*input.begin());

  for (std::size_t i{0}; i < input.size() ; ++i)
    if(input[i] == '\n') {
      grid.push_back(std::string{p, &input[i]});
      p = &input[i + 1];
    }

  REQUIRE(countRatios(grid) == 531561);
}

int main(int argc, char *argv[]) {
  return Catch::Session().run(argc, argv);
}
