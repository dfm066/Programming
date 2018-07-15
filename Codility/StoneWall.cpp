

// you can use includes, for example:
// #include <algorithm>
#include <unordered_map>
#include <set>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;

int solution(vector<int> &H) {
    unordered_map<int, set<int>>  uniq_bricks;
    int curr_sz = 1000000001;
    int cnt = 0;
    for (auto h:H) {
        if (curr_sz > h) {
            uniq_bricks[curr_sz].insert(curr_sz);
            curr_sz = h;
        } else if (curr_sz < h) {
            uniq_bricks[curr_sz].insert(h);
        }
    }
    for (auto s:uniq_bricks)    cnt += (int)s.second.size();
    return cnt;
}