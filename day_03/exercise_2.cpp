#include "exercise_2.hpp"

#include <array>
static constexpr const char* digits = "0123456789";

std::pair<size_t, size_t> p2::getNumIndexes(std::string_view line, size_t pos) {
  auto first { line.find_last_not_of (digits, pos) };
  auto last  { line.find_first_not_of(digits, pos) };
  first = (first == std::string::npos) ? 0               : ++first;
  last  = (last  == std::string::npos) ? line.size() - 1 : --last;
  return {first, last};
}

std::pair<int, size_t> p2::getLineNumber(std::string_view line, size_t pos) {
  int count{0};
  const auto [first, last] = p2::getNumIndexes(line, pos);
  for (size_t i{first}; i <= last; ++i)
    count = count * 10 + (line[i] - '0');
  return {count, first};
}

unsigned int countAdjacent(const std::vector<std::string>& grid,
    int si, int sj, const char*& lastpos, std::pair<int, int>& counted) {
  if((si >= 0 and sj >= 0 and si < grid.size() and sj < grid[si].size())
      and std::isdigit(grid[si][sj])) {
    const auto [num, first] = p2::getLineNumber(grid[si], sj);
    if(&grid[si][first] != lastpos) {
      lastpos = &grid[si][first];
      if(counted.first == 0) counted.first = num;
      else if(counted.second == 0) {
        counted.second = num;
        return counted.first * counted.second;
      }
    }
  }
  return 0;
}

static constexpr const std::array<std::pair<int, int>, 8> coord {{
   {-1, -1}, {-1, 0}, {-1, +1},
   { 0, -1},          { 0, +1},
   {+1, -1}, {+1, 0}, {+1, +1}
}};

unsigned int p2::countRatios(const std::vector<std::string> &grid) {
  unsigned int count{0};
  const char* lastpos{}; 
  for(size_t i{0}; i < grid.size(); ++i)
    for(size_t j{0}; j < grid[i].size(); ++j)
      if(grid[i][j] == '*') {
        std::pair<int, int> counted{0, 0};
        for (auto [di, dj] : coord) {
          count += countAdjacent(grid, i + di, j + dj, lastpos, counted);
        }
      }
  return count;
}
