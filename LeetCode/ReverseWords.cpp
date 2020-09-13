#include "Library/C++/utils.h"

std::string reverse_words(std::string line) {
  std::reverse(line.begin(), line.end());
  int curr = 0, we = 0, sz = line.size();
  do {
    while (curr < sz && !std::isalpha(line[curr])) curr++;
    we = std::distance(line.begin(),
                       std::find(line.begin() + curr, line.end(), ' '));
    std::reverse(line.begin() + curr, line.begin() + we);
    curr = we+1;
  } while (we != sz);
  return line;
}

int main() {
  std::string line;
  std::getline(std::cin, line);

  std::cout << reverse_words(line) << std::endl;
  return 0;
}
