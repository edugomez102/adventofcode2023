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

  inline std::vector<std::string_view> split(std::string& str, const char sep) {
    std::stringstream sstr{str};
    std::string segment {};

    std::vector<std::string_view> result;
    while(std::getline(sstr, segment, sep)) 
      result.push_back(segment);
    return result;
  }

  /**
   * @brief join a vector of strings to a single string
   *
   * @param v input vector
   * @param del char value to insert between vector values, default to none
   */
  inline std::string join(const std::vector<std::string>& v, const char del = '\0') {
    std::string s{};
    for (const auto& part : v) { 
      s += part;
      if (&part != &*(v.end() - 1)) s += del;
    }
    return s;
  }

}
