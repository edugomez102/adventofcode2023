#include <chrono>
#include <iostream>
#include <format>

namespace edgs {

  inline void printRunTime(auto fun) {
    auto start    = std::chrono::high_resolution_clock::now();
    fun();
    auto end      = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << std::format("Run time: {}\n", duration);
  }

}
