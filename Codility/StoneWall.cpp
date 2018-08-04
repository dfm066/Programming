#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &H) {
    // write your code in C++14 (g++ 6.2.0)
    int cnt = 0;
    stack<int> bricks;

    for(auto val:H) {
        while (!bricks.empty() && bricks.top() > val)   bricks.pop();
        if (bricks.empty() ||
            bricks.top() < val) {
            cnt++;
            bricks.push(val);
        }
    }
    return cnt;
}