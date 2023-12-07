#include <catch2/catch_all.hpp>
#include "exercise.hpp"
#include <fstream>

TEST_CASE("example 1") {
  REQUIRE(getCalibrationLine("1abc2") == 12);
}

TEST_CASE("example 2") {
  REQUIRE(getCalibrationLine("pqr3stu8vwx") == 38);
}

TEST_CASE("example 3") {
  REQUIRE(getCalibrationLine("a1b2c3d45f") == 15);
}

TEST_CASE("example 4") {
  REQUIRE(getCalibrationLine("treb7uchet") == 77);
}



TEST_CASE("sum of all") {
  REQUIRE(sumCalibrationValues(
        "1abc2\n"
        "pqr3stu8vwx\n"
        "a1b2c3d45f\n"
        "treb7uchet\n"
        ) == 142);
}


TEST_CASE("example 5") {
  REQUIRE(getCalibrationLine("two1nine") == 29);
}

TEST_CASE("example 6") {
  REQUIRE(getCalibrationLine("eighttwothree") == 83);
}

TEST_CASE("example 7") {
  REQUIRE(getCalibrationLine("abcone2threexyz") == 13);
}

TEST_CASE("example 8") {
  REQUIRE(getCalibrationLine("xtwone3four") == 24);
}

TEST_CASE("example 9") {
  REQUIRE(getCalibrationLine("4nineeightseven2") == 42);
}
TEST_CASE("example 10") {
  REQUIRE(getCalibrationLine("7pqestsixteen") == 76);
}


TEST_CASE("sum of all with strings") {
  REQUIRE(sumCalibrationValues(
        "two1nine\n"
        "eightwothree\n"
        "abcone2threexyz\n"
        "xtwone3four\n"
        "4nineeightseven2\n"
        "zoneight234\n"
        "7pqrstsixteen\n") == 281);
}
TEST_CASE("input 2") {
  std::ifstream file{"input2.txt", std::ios::binary};
  std::string str{std::istreambuf_iterator<char>(file),
                  std::istreambuf_iterator<char>()};

  REQUIRE(sumCalibrationValues(str) == 54019);
}


int main(int argc, char *argv[]) {
  return Catch::Session().run(argc, argv);
}
