#pragma once

#include <string>

namespace p1 {
  std::pair<int, bool> isGamePossible(std::string_view game);

  int countValidGames(std::string_view filename);

}

