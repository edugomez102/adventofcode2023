#include "exercise_1.hpp"
#include "exercise_2.hpp"
#include <iostream>

int main() {
  
  std::cout << p1::getTotalPoints("input.txt") << "\n";
  std::cout << p2::getTotalScratchCards("input.txt") << "\n";
  return 0;
}

