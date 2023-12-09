#include "exercise_1.hpp"
#include "exercise_2.hpp"
#include <utils.hpp>

#include <iostream>
#include <string>

int main() {

  edgs::printRunTime([] {
      std::cout << p1::countValidGames("input.txt") << "\n";
  });

  edgs::printRunTime([] {
      std::cout << p2::countPowerOfGames("input.txt") << "\n";
  });

  return 0;
}

