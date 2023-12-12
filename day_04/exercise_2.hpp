#pragma once 

#include <string>
#include <cstdint>
#include <vector>

namespace p2 {

  uint32_t getNumber(std::string_view line, size_t i);


  uint32_t getTotalScratchCards(std::string_view filename);
}

