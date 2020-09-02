#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

// #include "utils.h"

using namespace std;

template <typename I>
bool isPalindrome(I num) {
  string x = to_string(num);
  for (int i = 0, j = x.size() - 1; i < j; ++i, --j) {
    if (x[i] != x[j]) return false;
  }
  return true;
}

long long problem_125(long long limit) {
  unordered_set<long long> ans;
  int range = floor(sqrt(limit));
  vector<long long> squares(range + 1);

  generate(squares.begin(), squares.end(), [n = -1]() mutable {
    n++;
    return n * n;
  });
  transform(squares.begin(), prev(squares.end()), next(squares.begin()),
            next(squares.begin()), std::plus<>{});
  int cnt = 0;
  for (int i = 0; i < squares.size(); ++i) {
    for (int j = i + 2; j < squares.size(); ++j) {
      long long sum = squares[j] - squares[i];
      if (sum < limit && isPalindrome(sum)) {
        ans.insert(sum);
      }
    }
  }
  return accumulate(ans.begin(), ans.end(), (long long)0);
}

int main() {
  cout << problem_125(100000000);
  return 0;
}