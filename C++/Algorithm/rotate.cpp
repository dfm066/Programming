#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "Library/C++/my_algorithm.h"
#include "Library/C++/utils.h"
#include "Library/C++/table_util.h"

// Tester
int main() {
  const int SIZE = 10;
  size_t cols = instrumented<double>::number_ops;
  std::vector<instrumented<int>> nums(SIZE);
  time_diff exec_t1, exec_t2;
  std::vector<double> counter(cols, 0.0);

  std::generate(nums.begin(), nums.end(), [n = 0]() mutable {
    n++;
    return n;
  });
  std::sort(nums.begin(), nums.end());
  fmt::print("Before rotate : {}\n", nums);
  instrumented<int>::initialize(SIZE);

  my_rotate(nums.begin(), nums.begin() + SIZE / 3, nums.end());

  double* count_p = instrumented<int>::counts;
  std::copy(count_p, count_p+counter.size(), counter.begin());
  fmt::print("Rotating at : {}\n", SIZE / 3);
  fmt::print("After rotate : {}\n", nums);

  size_t decimals[cols];
  *decimals = 0;
  std::fill(decimals + 1, decimals + cols, 0);
  table_util table;
  table.print_headers(instrumented<double>::counter_names,
                      instrumented<double>::number_ops, 12);
  table.print_row(counter.begin(), decimals);
  return 0;
}