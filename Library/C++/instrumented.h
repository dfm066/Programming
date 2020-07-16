#ifndef INSTRUMENTED_H
#define INSTRUMENTED_H

#include <cstddef>

struct instrumented_base {
  enum operations {
    n,
    copy,
    assignment,
    destructor,
    default_constructor,
    equality,
    comparison,
    construction,
    move_construction,
    move_assignment
  };
  static const size_t number_ops = 10;
  static double counts[number_ops];
  static const char* counter_names[number_ops];
  static void initialize(size_t);
};

template <typename T>
struct instrumented : instrumented_base {
  typedef T value_type;
  T value;

  explicit instrumented(const T& x) : value(x) { ++counts[construction]; }

  explicit instrumented(T&& x) : value(move(x)) { ++counts[move_construction]; }

  // Semiregular:
  instrumented(const instrumented& x) : value(x.value) { ++counts[copy]; }
  instrumented(instrumented& x) : value(x.value) { ++counts[copy]; }
  instrumented(instrumented&& x) : value(move(x.value)) {
    ++counts[move_construction];
  }
  instrumented() : value() { ++counts[default_constructor]; }
  template <typename... U>
  instrumented(U&&... u) : value(T(std::forward<U>(u)...)) {
    ++counts[move_construction];
  }

  ~instrumented() { ++counts[destructor]; }

  instrumented& operator=(const instrumented& x) {
    ++counts[assignment];
    value = x.value;
    return *this;
  }
  instrumented& operator=(instrumented&& x) {
    ++counts[move_assignment];
    value = move(x.value);
    return *this;
  }
  // Regular
  friend bool operator==(const instrumented& x, const instrumented& y) {
    ++counts[equality];
    return x.value == y.value;
  }
  friend bool operator!=(const instrumented& x, const instrumented& y) {
    return !(x == y);
  }
  // TotallyOrdered
  friend bool operator<(const instrumented& x, const instrumented& y) {
    ++counts[comparison];
    return x.value < y.value;
  }
  friend bool operator>(const instrumented& x, const instrumented& y) {
    return y < x;
  }
  friend bool operator<=(const instrumented& x, const instrumented& y) {
    return !(y < x);
  }
  friend bool operator>=(const instrumented& x, const instrumented& y) {
    return !(x < y);
  }
};

template <typename T1, typename T2>
struct instrumented_pair : instrumented_base {
  typedef T1 first_type;
  typedef T2 second_type;
  T1 first;
  T2 second;
  explicit instrumented_pair(const std::pair<T1, T2>& x)
      : first(x.first), second(x.second) {
    ++counts[construction];
  }
  explicit instrumented_pair(std::pair<T1, T2>&& x)
      : first(move(x.first)), second(move(x.second)) {
    ++counts[move_construction];
  }
  template <class _Other1, class _Other2>
  constexpr explicit instrumented_pair(_Other1&& _Val1, _Other2&& _Val2)
      : first(std::forward<_Other1>(_Val1)),
        second(std::forward<_Other2>(_Val2)) {
    ++counts[move_construction];
  }

  // Semiregular:
  instrumented_pair(const instrumented_pair& x)
      : first(x.first), second(x.second) {
    ++counts[copy];
  }
  instrumented_pair(instrumented_pair& x) : first(x.first), second(x.second) {
    ++counts[copy];
  }
  instrumented_pair(instrumented_pair&& x)
      : first(move(x.first)), second(move(x.second)) {
    ++counts[move_construction];
  }
  instrumented_pair(const T1& first, const T2& second)
      : first(first), second(second) {
    ++counts[construction];
  }
  instrumented_pair(T1& first, T2& second) : first(first), second(second) {
    ++counts[construction];
  }
  instrumented_pair(T1&& first, T2&& second)
      : first(move(first)), second(first(second)) {
    ++counts[move_construction];
  }

  template <typename... U, typename... V>
  instrumented_pair(U&&... u, V&&... v) : first(T1(std::forward<U>(u)...), T2(std::forward<V>(v)...)) {
    ++counts[move_construction];
  }

  instrumented_pair() {
    ++counts[default_constructor]; }
  ~instrumented_pair() {
    ++counts[destructor]; }



  instrumented_pair& operator=(const instrumented_pair& x) {
    ++counts[assignment];
    first = x.first;
    second = x.second;
    return *this;
  }
  instrumented_pair& operator=(instrumented_pair&& x) {
    ++counts[move_assignment];
    first = move(x.first);
    second = move(x.second);
    return *this;
  }
  // Regular
  friend bool operator==(const instrumented_pair& x,
                         const instrumented_pair& y) {
    ++counts[equality];
    return x.first == y.first;
  }
  friend bool operator!=(const instrumented_pair& x,
                         const instrumented_pair& y) {
    return !(x == y);
  }
  // TotallyOrdered
  friend bool operator<(const instrumented_pair& x,
                        const instrumented_pair& y) {
    ++counts[comparison];
    return x.first < y.first;
  }
  friend bool operator>(const instrumented_pair& x,
                        const instrumented_pair& y) {
    return y < x;
  }
  friend bool operator<=(const instrumented_pair& x,
                         const instrumented_pair& y) {
    return !(y < x);
  }
  friend bool operator>=(const instrumented_pair& x,
                         const instrumented_pair& y) {
    return !(x < y);
  }
};

double instrumented_base::counts[];
const char* instrumented_base::counter_names[number_ops] = {
    "n",     "copy", "assign",    "destruct",          "default",
    "equal", "less", "construct", "move_construction", "move_assignment"};
void instrumented_base::initialize(size_t m) {
  std::fill(counts, counts + number_ops, 0.0);
  counts[n] = double(m);
}

#endif