#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "Library/C++/instrumented.h"
#include "Library/C++/my_algorithm.h"
#include "Library/C++/table_util.h"
#include "Library/C++/utils.h"

// Tester
int main() {
  const int SIZE = 100000;
  const int TEST = 100;
  size_t cols = instrumented<double>::number_ops;
  std::vector<instrumented<int>> nums(SIZE);
  time_diff exec_t1, exec_t2;
  std::vector<double> counters1(cols, 0.0), counters2(cols, 0.0);

  for (int i = 0; i < TEST; ++i) {
    std::generate(nums.begin(), nums.end(), [n = 0]() mutable {
      n++;
      return n % (SIZE / TEST);
    });
    std::sort(nums.begin(), nums.end());
    instrumented<int>::initialize(SIZE);

    auto st = GET_HRTIME();
    my_unique(nums.begin(), nums.end());
    auto en = GET_HRTIME();
    exec_t1 += en - st;

    double* count_p = instrumented<int>::counts;
    for (int j = 0; j < counters1.size(); ++j) {
      counters1[j] += count_p[j];
    }
  }

  for (int i = 0; i < TEST; ++i) {
    std::generate(nums.begin(), nums.end(), [n = 0]() mutable {
      n++;
      return n % (SIZE / TEST);
    });
    std::sort(nums.begin(), nums.end());
    instrumented<int>::initialize(SIZE);

    auto st = GET_HRTIME();
    my_unique_slow(nums.begin(), nums.end());
    auto en = GET_HRTIME();
    exec_t2 += en - st;

    double* count_p = instrumented<int>::counts;
    for (int j = 0; j < counters2.size(); ++j) {
      counters2[j] += count_p[j];
    }
  }

  for (int j = 0; j < counters2.size(); ++j) {
    counters1[j] /= TEST;
    counters2[j] /= TEST;
  }
  exec_t1 /= TEST;
  exec_t2 /= TEST;

  size_t decimals[cols];
  *decimals = 0;
  std::fill(decimals + 1, decimals + cols, 0);
  table_util table;
  table.print_headers(instrumented<double>::counter_names,
                      instrumented<double>::number_ops, 12);
  table.print_row(counters1.begin(), decimals);
  table.print_row(counters2.begin(), decimals);

  fmt::print("Total time (fast): {}us\n", us(exec_t1).count());
  fmt::print("Total time (slow): {}us\n", us(exec_t2).count());
  return 0;
}