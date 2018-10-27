#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;
bool vis[MAXN];
int ar[MAXN];
int pre[MAXN];
vector<int> v;
int dp[MAXN];

void sieve() {
  v.push_back(2);
  for (int i = 3; i < MAXN; i += 2)
    if (!vis[i]) {
      v.push_back(i);
      for (int j = i * i; j < MAXN; j += 2 * i)
        vis[j] = true;
    }
}
int main() {
  int n;
  cin >> n;
  assert(n <= 5000);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ar[i]);
    assert(ar[i] <= 100000);
    pre[i] = pre[i - 1] + ar[i];
  }
  sieve();
  dp[0] = dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1];
    for (int j = 0; j < (int)v.size() and v[j] <= i; j++) {
      int p = i - v[j] - 1;
      if (p == -1)
        dp[i] = max(dp[i], pre[i]);
      else
        dp[i] = max(dp[i], dp[p] + pre[i] - pre[p + 1]);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
