#include "exercise_2.hpp"

#include <unordered_map>
#include <fstream>
#include <algorithm>

// line[i] white, line[i + 1] first, line[i + 2] second
uint32_t p2::getNumber(std::string_view line, size_t i) {
  return ((line[i + 1] == ' ') ? 0 : line[i + 1] - '0')
          * 10 + (line[i + 2] - '0');
}

std::pair<std::vector<uint32_t>, std::vector<uint32_t>> getVectors(std::string_view line) {
  std::vector<uint32_t> mycards{}, wincards{};
  size_t i{5};
  for(; line[i] != ':'; ++i) {}
  i += 1;
  for(size_t j{0} ; line[i + 1] != '|'; i += 3, ++j)
    wincards.push_back(p2::getNumber(line, i));
  i += 2;
  for(; i < line.size(); i += 3) 
    mycards.push_back(p2::getNumber(line, i));
  return {mycards, wincards};
}

uint32_t p2::getTotalScratchCards(std::string_view filename) {
  std::unordered_map<uint32_t, uint32_t> card_counts{};
  uint32_t cardid{0};
  std::ifstream file{filename.data()};
  for(std::string line{}; std::getline(file, line);) {
    ++cardid;
    const auto [mycards, wincards] = getVectors(line);
    int newCards{0};
    for (const int& num : wincards)
      if(std::find(mycards.begin(), mycards.end(), num) != mycards.end())
        newCards++;

    for(uint32_t k = cardid + newCards; k > cardid; k--)
      card_counts[k] += (1 + card_counts[cardid]);
  }
  uint32_t total{0};
  for (const auto& [key, value] : card_counts) total += value;
  return total + cardid;
}
