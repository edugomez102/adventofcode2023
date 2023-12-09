#include "exercise_2.hpp"

#include <iostream>
#include <fstream>

unsigned int getColorNumber(std::string_view game, size_t i) {
  // check 0 - 1
  if (game[i - 3] == ' ') 
    return game[i - 2] - '0';
  // check 10 - 99
  else {
    return (game[i - 3] - '0') * 10 + (game[i - 2] - '0');
  }
}

unsigned int p2::powerOfGame(std::string_view game) {
  size_t i{5};
  int r{0}, g{0}, b{0};
  for (; i < game.size(); i++)
    if(game[i] == ':') break;

  for (++i; i < game.size(); ++i) {
    if(game[i] == 'r' and game[i - 1] != 'g') {
      const auto nr = getColorNumber(game, i);
      if(r < nr) r = nr;
    }
    else if(game[i] == 'g') {
      const auto ng = getColorNumber(game, i);
      if(g < ng) g = ng;
    }
    else if(game[i] == 'b') {
      const auto nb = getColorNumber(game, i);
      if(b < nb) b = nb;
    }
  }
  return r * g * b;
}

unsigned int p2::countPowerOfGames(std::string_view filename) {
  int total{0};
  std::ifstream file{filename.data()};
  for(std::string line{}; std::getline(file, line);)
    total += powerOfGame(line);
  return total;
}

int main() { 
  std::cout << p2::countPowerOfGames("input.txt");
}
