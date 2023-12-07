#include <algorithm>
#include <fstream>
#include <array>

template <typename T>
concept StringViewIt = std::is_same_v<T, typename std::string_view::iterator> || 
                       std::is_same_v<T, typename std::string_view::reverse_iterator>;

using numarr_t = std::array<std::string_view, 9>;

constexpr numarr_t numbers = {
  "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};
constexpr numarr_t rnumbers = {
  "eno",  "owt", "eerht", "ruof", "evif", "xis", "neves", "thgie", "enin" 
};

template <StringViewIt T>
int getFirstDigit(T begin, T end, const numarr_t& ar) {
  std::string s{};
  for (auto& it = begin; it != end; it++) {
    s += *it;
    if(std::isdigit(*it)) return *it - '0';
    else if(s.size() >= 3)
      for (std::size_t i{0}; i < ar.size(); ++i)
        if(s.find(ar[i]) != std::string::npos)
          return (i + 1);
  }
  return {};
}

int getCalibrationLine(std::string_view line) {
  int first = getFirstDigit(line.begin(),  line.end(),  numbers);
  int last  = getFirstDigit(line.rbegin(), line.rend(), rnumbers);
  return first * 10 + last;
}

int sumCalibrationValues(std::string_view values) {
  int count{0};
  const std::string_view::value_type* p = values.begin();
  for (std::size_t i{0}; i < values.size(); ++i)
    if(values[i] == '\n') {
      count += getCalibrationLine(std::string_view{p, &values[i]});
      p = &values[i];
    }
  return count;
}
