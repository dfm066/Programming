#include <bits/stdc++.h>

using Point = std::pair<int, int>;
using ns = std::chrono::duration<double, std::nano>;
using us = std::chrono::duration<double, std::micro>;
using ms = std::chrono::duration<double, std::milli>;
using time_diff = std::chrono::duration<double>;

#define SemigroupOperation typename
#define Regular typename
#define Integer typename
#define MultiplicativeSemiGroup typename
#define GET_HRTIME()  std::chrono::steady_clock::now()


std::vector<int> primes2n(int n);

template <Regular R> inline bool odd(const R &n) { return n & 1; }

template <Regular R> inline R half(const R &n) { return n >> 1; }

template <Regular R, Integer N, SemigroupOperation Op>
R semigroup_accumulate_operation(R r, R a, N n, Op op) {
  if (n == 0)
    return r;
  while (true) {
    if (odd(n)) {
      r = op(r, a);
      if (n == 1)
        return r;
    }
    n = half(n);
    a = op(a, a);
  }
}

template <Regular R, Integer N, SemigroupOperation Op>
R semigroup_operation(R a, N n, Op op) {
  while (!odd(n)) {
    a = op(a, a);
    n = half(n);
  }
  if (n == 1)
    return a;
  return semigroup_accumulate_operation(a, op(a, a), half(n - 1), op);
}

template <MultiplicativeSemiGroup T, Integer N>
struct power : public std::binary_function<T, N, T> {
  T operator()(const T &x, const N &y) {
    return semigroup_operation(x, y, std::multiplies<T>());
  }
};

struct bigint {
  std::vector<int> digits;
  bigint() { digits.reserve(32); };
  bigint(const bigint &x) : digits(x.digits){};
  bigint(int num) {
    int it = 0;
    digits.reserve(32);
    while (num) {
      digits.push_back(num % 10);
      num /= 10;
    }
  };

  size_t size() const { return digits.size(); };

  friend bool operator==(const bigint &x, const int i);

  friend bool operator&(const bigint &x, const int n);

  friend bool operator<(const bigint &x, const bigint &y);

  friend bigint operator-(const bigint &x, const int &n);

  friend bigint operator>>(const bigint &x, const int &n);

  friend bigint operator+(const bigint &x, const bigint &y);

  friend bigint operator*(const bigint &x, const bigint &y);

  friend std::ostream &operator<<(std::ostream &out, const bigint &x);
};
