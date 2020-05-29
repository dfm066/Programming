/*
 * Prime pair sets
 *
 * Problem 60
 *
 * The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes
 * and concatenating them in any order the result will always be prime.
 * For example, taking 7 and 109, both 7109 and 1097 are prime.
 * The sum of these four primes, 792, represents the lowest sum for a set of
 * four primes with this property.
 *
 * Find the lowest sum for a set of five primes for which any two primes
 * concatenate to produce another prime.
 *
 */

#include <map>

#include "utils.h"

using namespace std;

template <Integer N> bool match(N a, N b) {
  // Check ab and ba are prime
  struct power<N, N> exp;
  N ab = a * exp(10, N(ceil(log10(b)))) + b;
  N ba = b * exp(10, N(ceil(log10(a)))) + a;

  // Test primality using miller test
  if (is_prime(ab, 5) && is_prime(ba, 5))
    return true;
  return false;
}

void brute_force() {
  vector<int> primes = primes2n(10000);
  map<int, vector<int>> summation;
  for (auto first = begin(primes); first != end(primes); first++) {
    for (auto second = next(first); second != end(primes); second++) {
      if (!match(*first, *second))
        continue;
      for (auto third = next(second); third != end(primes); third++) {
        if (!match(*first, *third) || !match(*second, *third))
          continue;
        // cout << "Found 3 : [" << *first << ", " << *second << ", " << *third
        // << "]" << endl;
        for (auto fourth = next(third); fourth != end(primes); fourth++) {
          if (!match(*first, *fourth) || !match(*second, *fourth) ||
              !match(*third, *fourth))
            continue;
          //  cout << "Found 4 : [" << *first << ", " << *second << ", " <<
          //  *third << ", " << *fourth << "]" << endl;
          for (auto fifth = next(fourth); fifth != end(primes); fifth++) {
            if (!match(*first, *fifth) || !match(*second, *fifth) ||
                !match(*third, *fifth) || !match(*fourth, *fifth))
              continue;
            int sum = *first + *second + *third + *fourth + *fifth;
            summation[sum] = {*first, *second, *third, *fourth, *fifth};
          }
        }
      }
    }
  }
  cout << "Solution : " << begin(summation)->first;
  cout << "[";
  for (const auto &val : begin(summation)->second)
    cout << val << ", ";
  cout << "\b\b]" << endl;
}

int main() {
  auto st_t = GET_HRTIME();
  brute_force();
  auto en_t = GET_HRTIME();
  time_diff exec_t = en_t - st_t;
  cout << "Time to execute : " << ms(exec_t).count() << "ms\t"
       << us(exec_t).count() << "us\t" << ns(exec_t).count() << "ns\n"
       << endl;
  return 0;
}