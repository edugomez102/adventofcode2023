#include "exercise_1.hpp"

#include <fstream>

// line[i] white, line[i + 1] first, line[i + 2] second
uint32_t p1::getNumber(std::string_view line, size_t i) {
  return ((line[i] == ' ') ? 0 : line[i] - '0')
          * 10 + (line[i + 1] - '0');
}

uint32_t p1::getCardPoints(std::string_view line) {
  uint32_t points{1};
  size_t i{5};
  std::vector<uint32_t> wincards;
  for(; line[i] != ':'; ++i) {}
  i += 2;
  for(size_t j{0} ; line[i] != '|'; i += 3, ++j)
    wincards.push_back(getNumber(line, i));
  i += 2;
  for(; i < line.size(); i += 3) {
    const auto number = getNumber(line, i);
    if(std::find(wincards.begin(), wincards.end(), number) != wincards.end())
      points *= 2;
  }
  return points == 1 ? 0 : points / 2;
}

uint32_t p1::getTotalPoints(std::string_view filename) {
  uint32_t total{0};
  std::ifstream file{filename.data()};
  for(std::string line{}; std::getline(file, line);) {
    total += p1::getCardPoints(line);
  }
  return total;
}

