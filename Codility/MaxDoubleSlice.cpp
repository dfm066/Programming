#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    vector<int> lmax(N), rmax(N);
    int curr_lmax, curr_rmax;
    int max_dslice = -10001;
    
    curr_lmax = 0, curr_rmax = 0;
    for (int x = 1, z = N-2; x < N-1; x++, z--) {
        lmax[x] = curr_lmax;
        rmax[z] = curr_rmax;
        curr_lmax = max(0, curr_lmax+A[x]);
        curr_rmax = max(0, curr_rmax+A[z]);
    }
    for (int y = 1; y < N-1; y++) {
        max_dslice = max(max_dslice, lmax[y]+rmax[y]);   
    }
    
    return max_dslice;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << solution(A);
    cout << endl;
    return 0;
}
