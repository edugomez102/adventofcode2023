#include "exercise_1.hpp"

#include <iostream>
#include <fstream>

static constexpr unsigned int R_MAX{12};
static constexpr unsigned int G_MAX{13};
static constexpr unsigned int B_MAX{14};

bool checkTwoBehind(std::string_view game, size_t i, unsigned int max) {
  // means number < 10
  if (game[i - 3] == ' ') return true;
  // check if number > max
  if ((game[i - 3] - '0') == 1   and
      (std::isdigit(game[i - 2]) and (game[i - 2] - '0') <= max % 10))
      return true;
  return false;
}

std::pair<unsigned int, bool> p1::isGamePossible(std::string_view game) {
  unsigned int id{0}; bool valid{true};
  std::size_t i {5};
  for (;i < game.size(); ++i) {
    if(game[i] == ':') break;
    id = 10 * id + (game[i] - '0');
  }
  for (++i; i < game.size(); ++i) {
    if(game[i] == 'r' and game[i - 1] != 'g')
      valid = checkTwoBehind(game, i, R_MAX);
    else if(game[i] == 'g')
      valid = checkTwoBehind(game, i, G_MAX);
    else if(game[i] == 'b')
      valid = checkTwoBehind(game, i, B_MAX);
    if(not valid) break;
  }
  return {id, valid};
}

unsigned int p1::countValidGames(std::string_view filename) {
  unsigned int total{0};
  std::ifstream file{filename.data()};
  for(std::string line{}; std::getline(file, line);) {
    auto gp = p1::isGamePossible(line);
    if(gp.second) total += gp.first;
  }
  return total;
}

int main() { 
  std::cout << p1::countValidGames("input.txt");
}

