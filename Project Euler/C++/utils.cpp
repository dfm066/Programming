#include "utils.h"

std::vector<int> primes2n(int n) {
  std::vector<bool> num_map(n + 1);
  std::vector<int> primes;

  std::fill(std::begin(num_map), std::end(num_map), true);
  primes.reserve(sqrt(n));

  for (int i = 2; i <= sqrt(n); ++i) {
    if (num_map[i]) {
      for (int sq = i * i, j = sq, k = 1; j <= n; ++k) {
        num_map[j] = false;
        j = sq + k * i;
      }
    }
  }

  for (int i = 2; i <= n; ++i) {
    if (num_map[i])
      primes.push_back(i);
  }

  return primes;
}

bool operator==(const bigint &x, const int i) {
  if (i == 0)
    return (x.digits.back() == 0);
  else if (i == 1)
    return (x.size() == 1 && x.digits[0] == 1);
  else
    return false;
}

bool operator&(const bigint &x, const int n) {
  if (n != 1)
    assert(0);
  return x.digits[0] & 1;
}

bool operator<(const bigint &x, const bigint &y) {
  if (x.size() < y.size())
    return true;
  if (x.size() > y.size())
    return false;
  int it = x.size() - 1;

  for (; it >= 0 && (x.digits[it] == y.digits[it]); it--)
    ;

  if (it < 0)
    return false;
  else
    return x.digits[it] < y.digits[it];
}

bigint operator-(const bigint &x, const int &n) {
  if (n != 1)
    assert(0);
  bigint res = x;
  int it = 0, lim = res.size();
  while (res.digits[it] == 0 && it < lim)
    it++;
  if (it == lim)
    assert(0);
  --res.digits[it--];
  while (it >= 0)
    res.digits[it--] = 9;
  if (res.digits.back() == 0)
    res.digits.pop_back();
  return res;
}

bigint operator>>(const bigint &x, const int &n) {
  if (n != 1)
    assert(0);
  bigint res = x;
  int it = res.size() - 1;
  int sum = 0;
  bool is_odd = false;
  while (it >= 0) {
    if (is_odd)
      sum = 10 + res.digits[it];
    else
      sum = res.digits[it];
    is_odd = false;
    if (sum & 1)
      is_odd = true;
    res.digits[it--] = sum >> 1;
  }
  if (res.digits.back() == 0)
    res.digits.pop_back();
  return res;
}

bigint operator+(const bigint &x, const bigint &y) {
  bigint res;
  const bigint *bigger;
  std::pair<size_t, size_t> n = std::minmax(y.size(), x.size());
  int it = 0;
  int carry = 0, sum = 0;

  if (y.size() == n.second)
    bigger = &y;
  else if (n.first != n.second)
    bigger = &x;

  for (; it < n.first; it++) {
    if (!carry) {
      res.digits.push_back(0);
    }
    sum = x.digits[it] + y.digits[it] + carry;
    carry = 0;
    if (sum < 10) {
      res.digits[it] += sum;
    } else {
      res.digits[it] += (sum - 10);
      res.digits.push_back(0);
      carry = 1;
    }
  }
  for (; it < n.second; it++) {
    if (!carry) {
      res.digits.push_back(0);
    }
    sum = bigger->digits[it] + carry;
    carry = 0;
    if (sum < 10) {
      res.digits[it] += sum;
    } else {
      res.digits[it] += (sum - 10);
      res.digits.push_back(0);
      carry = 1;
    }
  }
  if (carry)
    res.digits[it] += carry;
  return res;
}

bigint operator*(const bigint &x, const bigint &y) {
  return semigroup_operation(x, y, std::plus<bigint>());
}

std::ostream &operator<<(std::ostream &out, const bigint &x) {
  for (auto it = x.digits.crbegin(); it != x.digits.crend(); it++) {
    out << *it;
  }
  return out;
}
