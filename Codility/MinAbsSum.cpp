#include "../Library/C++/utils.h"
using namespace std;

const int limit = 100;
const int sz = limit+1;

void print_partitions(vector<vector<int>> &p, const string &msg) {
    cout << msg;
    for(auto part : p) {
        for (int i = part.size()-1; i > 0; i--) {
            for (int j = 0; j < part[i]; j++) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}
vector<vector<int>> uniq_partitions(int n) {
    int p[n];
    int k = 0;
    p[k] = n;
    vector<vector<int>> partitions;
    partitions.reserve(n);
    while(true) {
        vector<int> parts(n+1, 0);
        for (int i = 0; i < k+1; i++)   parts[p[i]]++;
        partitions.push_back(parts);
        int rem_val = 0;
        while (k >= 0 && p[k] == 1) {
            rem_val++;
            k--;
        }
        if (k < 0)  return partitions;
        p[k]--;
        rem_val++;
        while(rem_val > p[k]) {
            p[k+1] = p[k];
            rem_val -= p[k];
            k++;    
        }
        p[k+1] = rem_val;
        k++;
    }
}

bool find_match(int guess, int *c_map, vector<vector<int>> &partitions) {
    int st = 0;
    if (!partitions[st][guess] && guess != 1) {
        while(partitions[st][guess] != 1 && partitions[st][1] != 1)  st++;
    }
    int rng = partitions.size();
    for (; st < rng; st++) {
        //print_partitions(partitions, "Trying for "+to_string(guess)+ " :\n");
        if (!partitions[0][guess]) {
            if (partitions[st][1] < 1)   continue;
            partitions[st][1]--;
        }
        bool found = true;
        vector<int> parts = ref(partitions[st]);
        for (int i = parts.size()-1; i > 0; i--) {
            if (parts[i] && parts[i] > c_map[i])   {
                found = false;
                break;
            }
        }
        if (found)  return true;
    }
    return false;
}
 int solution(vector<int> &A) {
    int c_map[sz] = {0};
    int min_diff = 0;
    for (auto n:A) {
        int idx = abs(n);
        c_map[idx]++;
        min_diff += idx;
    }
    int possible;
    int it = limit;
    while (min_diff && it > 0) {
        if (c_map[it]) {
            int reduce =  it * 2;
            int r_cnt = c_map[it];
            for (int i = 0; i < r_cnt && min_diff < abs(min_diff - reduce); i++) {
                min_diff -= reduce;
                c_map[it]--;
            }
        }
       it--;
    }
    if  (!min_diff) {
        return 0;
    }
    possible = min_diff >> 1;
    min_diff = min_diff - (possible << 1);
    if (!possible)  return min_diff;
    for (it = 1; !c_map[it]; it++);
    if (possible <= it) return 2*possible + min_diff;
    vector<vector<int>> partitions = uniq_partitions(possible);

    for (int guess = possible; guess > 0; guess--) {
        if (find_match(guess, c_map, partitions)) {
            break;
        }
        min_diff += 2;
    }
    return min_diff;
}
int main() {
    int N, it = 0;
    cin >> N;
    vector<int> A(N);
    while(N--) {
        cin >> A[it++];
    }
    cout << "Solution : " << solution(A) << endl;
    return 0;
}