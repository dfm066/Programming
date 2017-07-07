#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MOD 1000000007
using namespace std;


int main() {
    long long sum,N,d,a;
    int T;
    cin >> T;
    while(T--){
        cin >> N;
        sum = 1;
        d = 2;
        a = 3;
        for(;N > 1; N-=2){
            sum = (sum + ( 2*(2*a + 3*d ) )% MOD) % MOD;
            a += 3*d;
            d += 2;
            a +=d;            
        }
        cout << sum << endl;
    }
    return 0;
}
