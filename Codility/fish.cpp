// you can use includes, for example:
// #include <algorithm>
#include <stack>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;
int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    stack<pair<int,int>> s;
    int sz = (int)A.size();
    for(int i = 0; i < sz; i++) {
        while (!s.empty()) {
            if (s.top().first < A[i] && (s.top().second == 1 && B[i] == 0))  s.pop();
            else break;
        }
        if (s.empty() || !(s.top().second == 1 && B[i] == 0)) s.push(make_pair(A[i],B[i]));
    }
    return s.size();
}
