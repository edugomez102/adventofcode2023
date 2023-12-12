#pragma once

#include <string>
#include <cstdint>
#include <algorithm>
#include <array>
#include <vector>

namespace p1 {

  uint32_t getNumber(std::string_view line, size_t i);

  uint32_t getCardPoints(std::string_view line);

  uint32_t getTotalPoints(std::string_view filename);

}

