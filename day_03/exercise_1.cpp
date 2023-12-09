#include "exercise_1.hpp"
#include <array>
#include <algorithm>

static constexpr const char* digits = "0123456789";

std::pair<size_t, size_t> p1::getNumIndexes(std::string_view line, size_t pos) {
  auto first { line.find_last_not_of (digits, pos) };
  auto last  { line.find_first_not_of(digits, pos) };
  first = (first == std::string::npos) ? 0               : ++first;
  last  = (last  == std::string::npos) ? line.size() - 1 : --last;
  return {first, last};
}

std::pair<int, size_t> p1::getLineNumber(std::string_view line, size_t pos) {
  int count{0};
  const auto [first, last] = p1::getNumIndexes(line, pos);
  for (size_t i{first}; i <= last; ++i)
    count = count * 10 + (line[i] - '0');
  return {count, first};
}

unsigned int countAdjacent(const std::vector<std::string>& grid,
    int si, int sj, const char*& lastpos) {
  if((si >= 0 and sj >= 0 and si < grid.size() and sj < grid[si].size())
      and std::isdigit(grid[si][sj])) {
    const auto [num, first] = p1::getLineNumber(grid[si], sj);
    if(&grid[si][first] != lastpos) {
      lastpos = &grid[si][first];
      return num;
    }
  }
  return 0;
}

static constexpr const std::array<std::pair<int, int>, 8> coord {{
   {-1, -1}, {-1, 0}, {-1, +1},
   { 0, -1},          { 0, +1},
   {+1, -1}, {+1, 0}, {+1, +1}
}};

// i j as input and iterate 3
unsigned int p1::countRatios(const std::vector<std::string>& grid) {
  unsigned int count{0};
  const char* lastpos{}; // pointer to last added value to avoid repetition
  for(size_t i{0}; i < grid.size(); ++i)
    for(size_t j{0}; j < grid[i].size(); ++j)
      if(!std::isdigit(grid[i][j]) and grid[i][j] != '.')
        for (auto [di, dj] : coord) // helper
          count += countAdjacent(grid, i + di, j + dj, lastpos);
  return count;
}
