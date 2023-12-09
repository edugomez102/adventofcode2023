#include "exercise_1.hpp"
#include "exercise_2.hpp"
#include <fstream>
#include <array>
#include <algorithm>

int main() {
  std::ifstream file{"input.txt"};
  std::vector<std::string> grid;
  for(std::string line{}; std::getline(file, line);) grid.push_back(line);

  auto total_1 = p1::countRatios(grid);
  auto total_2 = p2::countRatios(grid);

  return 0;
}

