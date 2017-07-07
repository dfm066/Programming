#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MOD 1000000007
using namespace std;


int main() {
    unsigned long long sum,N,t1,t2,t3,n;
    int T;
    cin >> T;
    while(T--){
        cin >> N;
        n = (N - 1) / 2;
        sum = t1 = t2 = t3 = 0;
        t1 = 8 * (n % MOD) * (n % MOD + 1) * (2 * (n % MOD) + 1) / 3;
        t2 = 2 * (n % MOD) * (n % MOD + 1);
        t3 = 4 * (n % MOD);
        sum = (t1 + t2 + t3 ) % MOD + 1;
        // cout << n << " " << t1 << " " << t2 << " " << t3 << endl;
        cout << sum << endl;
    }
    return 0;
}
