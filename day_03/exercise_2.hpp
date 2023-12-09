#pragma once 

#include <vector>
#include <string>

namespace p2 {

  using size_t = std::size_t;

  std::pair<size_t, size_t> getNumIndexes(std::string_view line, size_t pos);

  std::pair<int, size_t> getLineNumber(std::string_view line, size_t pos);

  unsigned int countRatios(const std::vector<std::string>& grid);

}
