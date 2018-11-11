/*
Author : dfm066

Problem 51

By replacing the 1st digit of the 2-digit number *3, it turns out that six of
the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit
number is the first example having seven primes among the ten generated numbers,
yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993.
Consequently 56003, being the first member of this family, is the smallest prime
with this property.

Find the smallest prime which, by replacing part of the number (not necessarily
adjacent digits) with the same digit, is part of an eight prime value family.

*/

#include "utils.h"

using namespace std;

pair<pair<int, int>, int> same_digits(int num) {
  int digits[10] = {0};
  int tmp = num;
  num = num / 10;
  while (num) {
    digits[num % 10]++;
    num /= 10;
  }
  int res = 0;
  int res_val = digits[0];
  for (int i = 1; i < 10; i++) {
    if (res < digits[i]) {
      res = i;
      res_val = digits[i];
    }
  }
  int mask = 0;
  int mult = 10;
  tmp /= 10;
  while (tmp) {
    if (tmp % 10 == res)
      mask += 1 * mult;
    tmp /= 10;
    mult *= 10;
  }
  return make_pair(make_pair(res, res_val), mask);
}

int prime_family(int sz) {
  auto primes = primes2n(int(1000000));
  int limit = primes.size();
  for (int it = 4; it < limit; it++) {
    int p = primes[it];
    pair<pair<int, int>, int> dc = same_digits(p);
    int digit = dc.first.first;
    int digits = ceil(log10(p));
    if (digit >= 0 && digit <= 9 - sz) {
      int cnt = 0;
      int mask = dc.second;
      int val = p - digit * mask;
      for (int i = 0; i < 10; i++) {
        int num = val + i * mask;
        if (digits != ceil(log10(num)))
          continue;
        if (binary_search(primes.begin(), primes.end(), num))
          cnt++;
      }
      if (cnt == sz) {
        cout << "prime : " << p << " mask : " << mask << " digit : " << digit
             << " val : " << dc.first.second << endl;
        for (int i = 0; i < 10; i++) {
          if (binary_search(primes.begin(), primes.end(), val + i * mask))
            cout << val + i * mask << ",  ";
        }
        cout << endl;
        return p;
      }
    }
  }
  return 0;
}

int main() {
  const int family_sz = 8;
  int smallest_prime = 0;

  auto st = GET_HRTIME();
  smallest_prime = prime_family(family_sz);
  auto en = GET_HRTIME();
  
  cout << "Solution : " << smallest_prime << endl;

  time_diff exec_t = en-st;
  cout << "Time to execute : " << ms(exec_t).count() << "ms\t" 
       << us(exec_t).count() << "us\t" << ns(exec_t).count() << "ns\n" <<  endl;
  return 0;
}