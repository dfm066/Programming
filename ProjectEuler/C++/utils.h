#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<assert.h>

#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>

#include<numeric>
#include<algorithm>
#include<chrono>
#include<random>
#include <functional>


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


/*
 * random number engine
 */
static std::default_random_engine e(time(0));

/*
 * Fast calculation of `a^x mod n´ by using right-to-left binary modular
 * exponentiation.
 *
 * See http://en.wikipedia.org/wiki/Modular_exponentiation
 */
size_t pow_mod(size_t a, size_t x, size_t n) {
    /*
     * Note that this code is sensitive to overflowing for testing of large
     * prime numbers.  The `a*r´ and `a*a´ operations can overflow.  One easy
     * way of solving this is to use 128-bit precision for calculating a*b % n,
     * since the mod operator should always get us back to 64bits again.
     *
     * You can either use GCC's built-in __int128_t or use
     *
     * typedef unsigned int uint128_t __attribute__((mode(TI)));
     *
     * to create a 128-bit datatype.
     */
    size_t r = 1;
    while (x) {
        if ((x & 1) == 1)
            r = a * r % n;
        a = a * a % n;
        x >>= 1;
    }
    return r;
}

/*
 * The Miller-Rabin probabilistic primality test.
 *
 * Returns true if ``n´´ is PROBABLY prime, false if it's composite.
 * The parameter ``k´´ is the accuracy.
 *
 * The running time should be somewhere around O(k log^3 n).
 *
 */
bool is_prime(size_t n, int k) {
    // Must have ODD n greater than THREE
    if (n == 2 || n == 3)
        return true;
    if (n <= 1 || !(n & 1))
        return false;

    // Write n-1 as d*2^s by factoring powers of 2 from n-1
    int s = 0;
    size_t d = n - 1;
    for (; !(d & 1); ++s, d >>= 1)
        ; // loop

    // Here, we CANNOT set it static
    std::uniform_int_distribution<size_t> u(2, n - 2);
    for (int i = 0; i < k; ++i) {
        size_t a = u(e);
        size_t reminder = pow_mod(a, d, n);
        if (reminder == 1 | reminder == (n - 1))
            continue;
        for (int r = 1; r <= s - 1; ++r) {
            reminder = pow_mod(reminder, 2, n);
            if (reminder == 1)
                return false; // n is not a prime, and a is a witness
            if (reminder == n - 1)
                goto NEXT_WITNESS;
        }
        return false;
    NEXT_WITNESS:
        continue;
    }
    return true; // n is *probably* prime
}

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
struct power {
  T operator()(const T &x, const N &y) {
    if (y == N(0)) return N(1);
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

void tokenize(const std::string &str, std::vector<std::string> &tokens,
	      const std::string &delimiters = " ") {
  std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
  std::string::size_type pos = str.find_first_of(delimiters, lastPos);
  while (std::string::npos != pos || std::string::npos != lastPos) {
    tokens.push_back(str.substr(lastPos, pos - lastPos));
    lastPos = str.find_first_not_of(delimiters, pos);
    pos = str.find_first_of(delimiters, lastPos);
  }
}

template <typename I>
void print_v(std::vector<I> vec)
{
  for (const auto& v: vec) {
    std::cout << v << ", ";
  }
  std::cout << std::endl;
}