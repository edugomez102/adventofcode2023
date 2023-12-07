#include "exercise.hpp"

#include <iostream>
#include <fstream>

// Minimal enviroment

int main()
{
  std::ifstream file{"input2.txt", std::ios::binary};
  std::string str{std::istreambuf_iterator<char>(file),
                  std::istreambuf_iterator<char>()};

  std::cout << sumCalibrationValues(str);

  return 0;
}
