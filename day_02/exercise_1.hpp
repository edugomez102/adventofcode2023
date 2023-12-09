#pragma once

#include <string>

namespace p1 {
  std::pair<unsigned int, bool> isGamePossible(std::string_view game);

  unsigned int countValidGames(std::string_view filename);

}

