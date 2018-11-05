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

template<Integer N>
inline bool
odd(const N& n)
{
  return n & 1;
}

template<Integer N>
inline N
half(const N& n)
{
  return n >> 1;
}

template<Regular R, Integer N, SemigroupOperation Op>
R
semigroup_accumulate_operation(R r, R a, N n, Op op)
{
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

template<Regular R, Integer N, SemigroupOperation Op>
R
semigroup_operation(R a, N n, Op op)
{
  if (n == 0)
    return R(0, a);
  while (!odd(n)) {
    a = op(a, a);
    n = half(n);
  }
  if (n == 1)
    return a;
  return semigroup_accumulate_operation(a, op(a, a), half(n - 1), op);
}

template<MultiplicativeSemiGroup T, Integer N>
struct power : public std::binary_function<T, N, T>
{
  T operator()(const T& x, const N& y)
  {
    return semigroup_operation(x, y, std::multiplies<T>());
  }
};

struct bigint
{
  std::vector<int> digits;
  bigint() { digits.reserve(32); };
  bigint(const bigint& x)
    : digits(x.digits){};
  bigint(int num)
  {
    int it = 0;
    if (num == 0) {
      digits.push_back(0);
      return;
    }
    digits.reserve(32);
    while (num) {
      digits.push_back(num % 10);
      num /= 10;
    }
  };

  bigint(int num, const bigint& x)
  {
    digits.reserve(x.size());
    for (int i = 0; i < x.size(); i++)
      digits.push_back(num);
  }
  size_t size() const { return digits.size(); };
  bigint& operator=(const bigint& x) { digits = x.digits; }

  friend bool operator==(const bigint& x, const int i);

  friend bool operator&(const bigint& x, const int n);

  friend bool operator<(const bigint& x, const bigint& y);

  friend bigint operator-(const bigint& x, const int& n);

  friend bigint operator>>(const bigint& x, const int& n);

  friend bigint operator+(const bigint& x, const bigint& y);

  friend bigint operator*(const bigint& x, const bigint& y);

  friend std::ostream& operator<<(std::ostream& out, const bigint& x);
};

bool
operator==(const bigint& x, const int i)
{
  if (i == 0)
    return (x.digits.back() == 0);
  else if (i == 1)
    return (x.size() == 1 && x.digits[0] == 1);
  else
    return false;
}

bool operator&(const bigint& x, const int n)
{
  if (n != 1)
    assert(0);
  return x.digits[0] & 1;
}

bool
operator<(const bigint& x, const bigint& y)
{
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

bigint
operator-(const bigint& x, const int& n)
{
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

bigint
operator>>(const bigint& x, const int& n)
{
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

bigint
operator+(const bigint& x, const bigint& y)
{
  bigint res;
  const bigint* bigger;
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

bigint operator*(const bigint& x, const bigint& y)
{
  return semigroup_operation(x, y, std::plus<bigint>());
}

std::ostream&
operator<<(std::ostream& out, const bigint& x)
{
  for (auto it = x.digits.crbegin(); it != x.digits.crend(); it++) {
    out << *it;
  }
  return out;
}

template<Integer I>
class matrix
{
private:
  int m, n;
  I** data;

public:
  matrix()
    : m(0)
    , n(0)
    , data(nullptr){};
  matrix(int r, int c)
    : m(r)
    , n(c)
  {
    data = new I*[m];
    for (int i = 0; i < m; i++) {
      data[i] = new I[n];
    }
  }
  matrix(const matrix<I>& mat)
  {
    m = mat.m;
    n = mat.n;
    data = new I*[m];
    for (int i = 0; i < m; i++) {
      data[i] = new I[n];
    }
    for (int i = 0; i < mat.m; i++) {
      for (int j = 0; j < mat.n; j++) {
        data[i][j] = mat[i][j];
      }
    }
  }

  matrix(I num, const matrix<I>& mat)
  {
    m = mat.m;
    n = mat.n;
    data = new I*[m];
    for (int i = 0; i < m; i++) {
      data[i] = new I[n];
    }
    if (num == 1) {
      for (int i = 0; i < std::min(mat.m, mat.n); i++) {
        data[i][i] = num;
      }
    } else {
      for (int i = 0; i < mat.m; i++) {
        for (int j = 0; j < mat.n; j++) {
          data[i][j] = num;
        }
      }
    }
  }
  ~matrix()
  {
    for (int i = 0; i < m; i++) {
      delete[] data[i];
    }
    delete[] data;
  }

  I* operator[](int i) { return data[i]; }

  const I* operator[](int i) const { return data[i]; }

  matrix<I>& operator=(const matrix<I>& mat)
  {
    if (this != &mat) {
      if (this->m != mat.m || this->n != mat.n) {
        this->~matrix();
        m = mat.m;
        n = mat.n;
        data = new I*[m];
        for (int i = 0; i < m; i++) {
          data[i] = new I[n];
        }
      }
      for (int i = 0; i < mat.m; i++) {
        for (int j = 0; j < mat.n; j++) {
          data[i][j] = mat[i][j];
        }
      }
    }

    return *this;
  }

  template<Integer T>
  friend matrix<I> operator+(const matrix<T>& x, const matrix<T>& y);

  template<Integer T>
  friend matrix<T> operator*(const matrix<T>& x, const matrix<T>& y);
  template<Integer T>
  friend bool operator==(const matrix<T>& x, const int i);
  template<Integer T>
  friend std::ostream& operator<<(std::ostream& out, const matrix<T>& mat);
};

template<Integer I>
matrix<I>
operator+(const matrix<I>& x, const matrix<I>& y)
{
  if (x.m != y.m || x.n != y.n)
    assert(0);
  matrix<I> res(x.m, x.n);
  for (int i = 0; i < x.m; i++) {
    for (int j = 0; j < x.n; j++) {
      res[i][j] = x[i][j] + y[i][j];
    }
  }
  return res;
}

template<Integer I>
matrix<I> operator*(const matrix<I>& x, const matrix<I>& y)
{
  if (x.n != y.m)
    assert(0);
  matrix<I> res(x.m, y.n);
  for (int i = 0; i < x.m; i++) {
    for (int j = 0; j < y.n; j++) {
      res[i][j] = I(0);
      for (int k = 0; k < x.n; k++) {
        res[i][j] = res[i][j] + x[i][k] * y[k][j];
      }
    }
  }
  return res;
}

template<Integer I>
std::ostream&
operator<<(std::ostream& out, const matrix<I>& mat)
{
  out << "Matrix : \n";
  for (int i = 0; i < mat.m; i++) {
    out << mat[i][0];
    for (int j = 1; j < mat.n; j++) {
      out << ", " << mat[i][j];
    }
    out << std::endl;
  }
  return out;
}

// Algorithms and Useful functions
template<RandomAccessIterator I, Integer N>
void
mark_sieve(I first, I last, N step)
{
  assert(first != last);
  *first = false;
  while (last - first > step) {
    first = first + step;
    *first = false;
  }
}

template<RandomAccessIterator I, Integer N>
void
sift(I first, N n)
{
  I last = first + n;
  std::fill(first, last, true);
  N i(0);
  N square(3);
  N step(3);
  while (square < n) {
    // invariant: square = 2i^2 + 6i + 3, step = 2i + 3
    if (first[i])
      mark_sieve(first + square, last, step);
    ++i;
    square += step;
    step += N(2);
    square += step;
  }
}

template<Integer N>
std::vector<N>
primes2n(N n)
{
  N map_sz = (n + 1) / 2 - 1;
  N step(3);
  N square(0);
  N s_step(2);
  std::vector<bool> num_map(map_sz);
  std::vector<N> primes;

  if (n < 2)
    return primes;
  primes.push_back(2);

  if (map_sz == 0)
    return primes;
  primes.reserve(map_sz);

  sift(std::begin(num_map), map_sz);

  for (N i = N(0); i < map_sz; ++i) {
    if (num_map[i])
      primes.push_back(square + step);
    square += s_step;
  }

  return primes;
}

template<Regular R, Integer N>
R
nth_fib(N n, matrix<R>& res)
{
  matrix<R> identity_mat(2, 2);
  matrix<R> start_val(2, 1);
  matrix<R> exp_fact;

  power<matrix<R>, N> exp_mat;

  identity_mat[0][0] = identity_mat[0][1] = identity_mat[1][0] =
    start_val[0][0] = R(1);
  identity_mat[1][1] = start_val[1][0] = R(0);

  exp_fact = exp_mat(identity_mat, n - 1);
  res = exp_fact * start_val;
  return res[0][0];
}