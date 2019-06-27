#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

string solution(const string &A, const string &B) {
  auto i = 0, j = 0;
  string ans;
  auto checked = 0, pt = 0;
  auto AS = A.size();
  auto BS = B.size();
  auto checker1 = AS, checker2 = BS;
  for (; i < AS && j < BS;) {
    if (i == pt) pt = 0, checked = 0;
    if (j == pt) pt = 0, checked = 0;
    if (A[i] > B[j])
      ans += B[j++];
    else if (A[i] < B[j])
      ans += A[i++];
    else {
      if (!checked) {
        checker1 = i + 1;
        checker2 = j + 1;
        while (checker1 != AS && checker2 != BS && A[checker1] == B[checker2])
          ++checker1, ++checker2;
        if (checker1 == AS) checker1--;
        if (checker2 == BS) checker2--;
        if (A[checker1] > B[checker2]) {
          checked = 2;
          pt = checker2;
          ans += B[j++];
        } else {
          checked = 1;
          pt = checker1;
          ans += A[i++];
        }
      } else if (checked == 1) {
        ans += A[i++];
      } else {
        ans += B[j++];
      }
    }
  }
  if (i != A.size())
    ans += A.substr(i);
  else if (j != B.size())
    ans += B.substr(j);
  return ans;
}

int main() {
  string ans, A, B;
  auto T = 0;
  cin >> T;
  while (T--) {
    cin >> A >> B;
    int remove = 0;
    if (A.size() > B.size()) {
      remove = 1;
      B+=char('Z'+1);
    } else if (A.size() < B.size()) {
      remove = 1;
      A+=char('Z'+1);
    }
    ans = solution(A,B);
    if (remove) {
      ans.erase(ans.size()-1,1);
    }
    cout << ans << endl;
  }
  return 0;
}
