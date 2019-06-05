#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> &A, vector<int> &B) {
    const int MAX_L = 50000;
    const int MAX_P = 30;
    int fib_no[MAX_L+1];
    int mod_p[MAX_P+1];
    int mod = 1;
    fib_no[0] = fib_no[1] = 1;
    mod_p[0] = mod;
    for (int i = 1; i < MAX_P+1; i++) {
        mod <<= 1;
        mod_p[i] = mod;
    }
    for (int i = 2; i < MAX_L+1; i++) {
        fib_no[i] = (fib_no[i-1] + fib_no[i-2]) % mod;
    }
    size_t len = A.size();
    vector<int> ans(len);
    for (size_t it = 0; it < len; it++){
        ans[it] = fib_no[A[it]] % mod_p[B[it]];
    }
    return ans;   
}

int main() {
    int L;
    cin>>L;
    vector<int> A, B;
    int num1, num2;
    for(int i = 0; i < L; i++){
        cin>>num1>>num2;
        A.push_back(num1);
        B.push_back(num2);
    }
    cout << "Solution : " << endl;
    vector<int> ans = solution(A,B);
    for(auto i : ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}