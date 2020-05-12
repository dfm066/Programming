#include "utils.h"
#include <cassert>
#include <cmath>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void problem_87() {
  const int limit = 50000000;
  int square_ulimit = floor(pow(limit - 28, 1.0 / 2));
  int cube_ulimit = floor(pow(limit - 20, 1.0 / 3));
  int fourth_ulimit = floor(pow(limit - 12, 1.0 / 4));
  vector<int> primes = primes2n(square_ulimit);
  unordered_map<int, int> squares, cubes, fourths;
  unordered_set<int> numbers;
  for (const auto &p : primes) {
    squares[p] = p * p;
    if (p <= cube_ulimit)
      cubes[p] = squares[p] * p;
    if (p <= fourth_ulimit)
      fourths[p] = cubes[p] * p;
  }
  int cnt = 0;
  for (const auto &f : fourths) {
    for (const auto &c : cubes) {
      for (const auto &s : squares) {
        int valid = s.second + c.second + f.second;
        if (valid < limit)
          numbers.insert(valid);
      }
    }
  }
  printf("Limits : %d, %d, %d\n", square_ulimit, cube_ulimit, fourth_ulimit);
  printf("Solution: %lu\n", numbers.size());
  return;
}

int main() {
  problem_87();
  return 0;
}