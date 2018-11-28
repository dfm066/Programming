#include "../Library/C++/utils.h"
using namespace std;

const int limit = 100;
const int sz = limit * 2 + 1;

void print_partiotions(vector<vector<int>> &p, const string &msg) {
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

bool find_match(int corr, int guess, int *c_map, vector<vector<int>> &partitions) {
    int st = 0;
    if (!partitions[st][guess]) {
        while(partitions[st][guess] != 1 && partitions[st][1] != 1)  st++;
    }
    int rng = partitions.size();
    for (; st < rng; st++) {
        if (partitions[st][1] < 1)   continue;
        partitions[st][1]--;
        bool found = true;
        vector<int> parts = ref(partitions[st]);
        for (int i = parts.size()-1; i > 0; i--) {
            if (parts[i] && parts[i] > c_map[i+corr])   {
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
    int p_sum = 0, n_sum = 0;
    for (auto n:A) {
        c_map[n+limit]++;
        if (n > 0)  p_sum += n;
        else n_sum += n;
        
    }
    int min_diff = p_sum + n_sum;
    int possible;
    int corr;
    if (min_diff < 0) {
        corr = 0;
        min_diff *= -1;
        possible = min_diff >> 1;
        min_diff = min_diff - (possible << 1);
    } else if (min_diff > 0) {
        corr = limit;
        possible = min_diff >> 1;
        min_diff = min_diff - (possible << 1);
    } else {
        return 0;
    }
    vector<vector<int>> partitions = uniq_partitions(possible);
    for (int guess = possible; guess > 0; guess--) {
        if (find_match(corr, guess, c_map, partitions)) {
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