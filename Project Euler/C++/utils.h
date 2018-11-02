#include <bits/stdc++.h>

using Point = std::pair<int, int>;
using ns = std::chrono::duration<double, std::nano>;
using us = std::chrono::duration<double, std::micro>;
using ms = std::chrono::duration<double, std::milli>;
using time_diff = std::chrono::duration<double>;

// Concepts - requirements on type
#define SemigroupOperation typename      // Operation must be associative
#define Regular typename                 // Type must be regular
#define Integer typename                 // Type must be interger
#define MultiplicativeSemiGroup typename // Semigroup must be multiplicative
#define RandomAccessIterator typename    // Iterator must be random access

#define GET_HRTIME() std::chrono::steady_clock::now()

template <RandomAccessIterator I, Integer N>
void mark_sieve(I first, I last, N step) {
  assert(first != last);
  *first = false;
  while (last - first > step) {
    first = first + step;
    *first = false;
  }
}

template <RandomAccessIterator I, Integer N>
void sift(I first, N n) {
  I last = first + n;
  std::fill(first, last, true);
  N i(0);
  N square(3);
  N step(3);
  while (square < n) {
    // invariant: square = 2i^2 + 6i + 3, step = 2i + 3
    if (first[i]) mark_sieve(first + square, last, step);
    ++i;
    square += step;
    step += N(2);
    square += step;
  }
}

template <Integer N>
std::vector<N> primes2n(N n) {
  N map_sz = (n+1)/2 - 1;
  N step(3);
  N square(0);
  N s_step(2);
  std::vector<bool> num_map(map_sz);
  std::vector<N> primes;

  if (n < 2)  return primes;
  primes.push_back(2);
  
  if (map_sz == 0)  return primes;
  primes.reserve(map_sz);

  sift(std::begin(num_map), map_sz);
  
  for (N i = N(0); i < map_sz; ++i) {
    if (num_map[i])
      primes.push_back(square + step);
    square += s_step;
  }

  return primes;
}

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
