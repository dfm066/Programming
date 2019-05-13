#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int ncr[100001];

#define ADD_TO_DP(x, val)       \
{                               \
    (x) = ((long long)(x) + (val)) % (MOD);  \
}

void print_vec(const int *v, int N, string str) {
    cout << str;
    for(int i = 0; i < N; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void init_ncr(int N) {
    int f = 1;
    ncr[0] = f - 1;
    for (int i = 0; i < N; i++) {
        f = (f * 2) % MOD;
        ncr[i+1] = f - 1;
    }
}

int main() {
    int N;
    scanf("%d",&N);
    int *A = new int[N];
    init_ncr(N);
    for (int i = 0; i < N; i++) {
        scanf("%d",&A[i]);
    }
    
    int ans = 0;
    int  *dp = new int[N];
    dp[0] = 0;
    int prev = 0;
    for (int i = 1; i < N; i++) {
        dp[i] = (long long)(dp[i-1] * 2) % MOD;
        for (int j = 0; j < i; j++) {
            if (abs(A[i] - A[j]) <= 1) {
                if (dp[j] && (j - prev - 1) > 0) {
                    ADD_TO_DP(dp[i], 2 * ncr[j-prev-1])
                }
                prev = j;
                ADD_TO_DP(dp[i], 1);
            }
        }
        // print_vec(dp, N, "DP : ");
    }
    
    printf("%d\n", dp[N-1]);
    delete[] A;
    delete[] dp;
    return 0;
}
