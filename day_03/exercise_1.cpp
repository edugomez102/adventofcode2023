#include "exercise_1.hpp"
#include <array>
#include <algorithm>

// bool is_symbol(const char character)
// {
//   return (character != '.' && ispunct(character));
// }
// bool checker(char c){
//   if(c == '.') return 0;
// 	if(48 <= c && c <= 57) return 0;
// 	return 1; 
// }

constexpr const char* digits = "0123456789";

std::pair<std::size_t, std::size_t> getNumIndexes(std::string_view line, std::size_t pos) {
  auto first { line.find_last_not_of (digits, pos) };
  auto last  { line.find_first_not_of(digits, pos) };
  first = (first == std::string::npos) ? 0               : ++first;
  last  = (last  == std::string::npos) ? line.size() - 1 : --last;
  return {first, last};
}

std::pair<int, std::size_t> getLineNumber(std::string_view line, std::size_t pos) {
  int count{0};
  const auto [first, last] = getNumIndexes(line, pos);
  for (std::size_t i{first}; i <= last; ++i) {
    count = count * 10 + (line[i] - '0');
  }
  return {count, first};
}

unsigned int countAdjacent(const std::vector<std::string>& grid,
    int si, int sj, const char*& lastpos) {
  if((si >= 0 and sj >= 0 and si < grid.size() and sj < grid[si].size())
      and std::isdigit(grid[si][sj])) {
    const auto [num, first] = getLineNumber(grid[si], sj);
    if(&grid[si][first] != lastpos) {
      lastpos = &grid[si][first];
      return num;
    }
  }
  return 0;
}

constexpr const std::array<std::pair<int, int>, 8> coord {{
   {-1, -1}, {-1, 0}, {-1, +1},
   { 0, -1},          { 0, +1},
   {+1, -1}, {+1, 0}, {+1, +1}
}};

// i j as input and iterate 3
unsigned int countRatios(const std::vector<std::string>& grid) {
  unsigned int count{0};
  const char* lastpos{}; // pointer to last added value to avoid repetition
  for(std::size_t i{0}; i < grid.size(); ++i)
    for(std::size_t j{0}; j < grid[i].size(); ++j)
      if(!std::isdigit(grid[i][j]) and grid[i][j] != '.')
        for (auto [di, dj] : coord)
          count += countAdjacent(grid, i + di, j + dj, lastpos);
  return count;
}
