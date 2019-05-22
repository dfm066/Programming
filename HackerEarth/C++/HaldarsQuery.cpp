#include <bits/stdc++.h>

using namespace std;

#define Integer typename                 // Type must be interger
#define RandomAccessIterator typename // Iterator must be random access

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
  N map_sz = ((n + 1) >> 1) - 1;
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
template<class ForwardIt, class T, class Compare=std::less<>>
ForwardIt binary_find(ForwardIt first, ForwardIt last, const T& value, Compare comp={})
{
     first = std::lower_bound(first, last, value, comp);
    return first != last && !comp(value, *first) ? first : last;
}

string solve (vector<int> &data, const vector<int> primes) {
    int N = data.size();
    vector<int> orig(N);
    for (int it = 0; it < N; ++it) {
        auto found = binary_find(primes.begin(), primes.end(), data[it]);
        if (found != primes.cend()) {
            orig[it] = distance(primes.begin(), found) + 1;
        } else {
            return "-1";
        }
    }
    string str;
    for (int it = 0; it < N; ++it) {
        str += to_string(orig[it]);
    } 
    cout << "Debug orig : " << str << endl;
    str.clear();
    if (next_permutation(begin(orig), end(orig))) {
      for (int it = 0; it < N; ++it) {
        str += to_string(orig[it]);
      } 
      return str;
    } else return "-1";
}

int main() {
    int T;
    cin >> T;
    int limit = 100000;
    vector<int> P = primes2n(limit);
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        cout << solve(A, P) << endl;
    }
}
