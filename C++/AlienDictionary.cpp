#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string printOrder(string dict[], int N, int k);

string order;

bool f(string a, string b) {
  int p1 = 0;
  int p2 = 0;
  for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
    p1 = order.find(a[i]);
    p2 = order.find(b[i]);
    //	cout<<p1<<" "<<p2<<endl;
  }

  if (p1 == p2 and a.size() != b.size())
    return a.size() < b.size();

  return p1 < p2;
}

// Driver program to test above functions
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s[n];
    for (int i = 0; i < n; i++)
      cin >> s[i];

    string ss = printOrder(s, n, k);
    order = "";
    for (int i = 0; i < ss.size(); i++)
      order += ss[i];

    string temp[n];
    std::copy(s, s + n, temp);
    sort(temp, temp + n, f);

    bool f = true;
    for (int i = 0; i < n; i++)
      if (s[i] != temp[i])
	f = false;

    cout << f;
    cout << endl;
  }
  return 0;
}

string::size_type find_missmatch(const string &a, const string &b) {
    string::size_type miss = 0;
    string::size_type limit = min(a.size(), b.size());
    while (miss < limit && a[miss] == b[miss]) {
      miss++;
    }
    if (miss == limit) return string::npos;
    return miss;
}

string printOrder(string dict[], int N, int k) {
  string order_map[128];
  for (int it = N - 2; it >= 0; it--) {
    cout << dict[it] << " <--> " << dict[it + 1] << endl;
    string::size_type  miss = find_missmatch(dict[it], dict[it+1]);
    if (miss == string::npos)
      miss--;
    string postfix;
    if (order_map[dict[it + 1][miss]].size() != 0)
        postfix = order_map[dict[it + 1][miss]];
    else postfix += dict[it + 1][miss];
    char needle = dict[it][miss];
    string hestack = "";
    string prefix(1, needle);
    while ((hestack = order_map[needle]).size() != 0) {
        auto found = hestack.find(dict[it + 1][miss]);
        if (found != string::npos) {
            prefix += hestack.substr(1, found - 1);
            break;
        }
        needle = hestack[hestack.size() - 1];
        prefix += hestack.substr(1, hestack.size() - 1);
    }
    order_map[dict[it][miss]] = prefix + postfix;
    cout << dict[it][miss] << " " << order_map[dict[it][miss]] << endl;
  }
  auto order = max_element(order_map, order_map + 128,
                            [](const string &a, const string &b) { 
                                return a.size() < b.size();
                            });
  return *order;
}
