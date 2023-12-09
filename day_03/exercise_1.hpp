#pragma once

#include <vector>
#include <string>

std::pair<std::size_t, std::size_t> getNumIndexes(std::string_view line, std::size_t pos);

std::pair<int, std::size_t> getLineNumber(std::string_view line, std::size_t pos);

unsigned int countRatios(const std::vector<std::string>& grid);
