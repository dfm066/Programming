#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int switchidx[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

pair<bool, ll>
calculate_divisibles(ll range, const vector<pair<ll, int>> &divisors, int len) {
  ll res = 0;
  int end = divisors.size();
  for (auto d : divisors) {
    if (d.second % 2 == 1)
      res += range / d.first;
    else
      res -= range / d.first;
  }
  bool is_valid = false;
  for (int i = 0; i < len; i++) {
    if (range % divisors[i].first == 0) {
      is_valid = true;
      break;
    }
  }
  return make_pair(is_valid, res);
}

ll find_bulbs(int *switches, ll k) {
  vector<pair<ll, int>> divisors;
  int len = sizeof(switchidx) / sizeof(int);

  for (int it = 0; it < len; it++) {
    if (switches[switchidx[it]])
      divisors.push_back(make_pair(switchidx[it], 1));
  }
  // ASSUMPTION there is atleast 1 switch on
  ll en = divisors[0].first * k;
  ll st = divisors[0].first;

  len = divisors.size();

  for (int sz = 2; sz <= len; sz++) {
    string bitmask(sz, 1);
    bitmask.resize(len, 0);
    do {
      ll num = 1;
      for (int i = 0; i < len; ++i) {
        if (bitmask[i])
          num *= divisors[i].first;
      }
      divisors.push_back(make_pair(num, sz));
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
  }

  pair<bool, ll> sol(false, 0);
  while (st <= en) {
    ll mid = (st + en) / 2;
    pair<bool, ll> res = calculate_divisibles(mid, divisors, len);
    if (k == res.second) {
      sol = make_pair(res.first, mid);
      break;
    } else if (k > res.second)
      st = mid + 1;
    else
      en = mid - 1;
  }
  if (sol.second == 0)
    return -1;
  if (sol.first == true)
    return sol.second;
  else {
    ll guess = sol.second;
    while (guess >= st) {
      pair<bool, ll> res = calculate_divisibles(guess, divisors, len);
      if (res.first == true && res.second == k)
        return guess;
      guess--;
    }
  }
}

int main() {
  int T;
  string S;
  ll K, ans;
  int switches[41];
  cin >> T;
  while (T--) {
    cin >> S >> K;
    for (int s = 0; s < 40; s++)
      switches[s + 1] = S[s] - '0';
    ans = find_bulbs(switches, K);
    cout << ans << endl;
  }
}