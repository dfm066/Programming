#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using ull = unsigned long long;
constexpr ull Modulus = 10000000000ULL;

inline ull modMul(const ull x, const ull y) {
	if (x > (1<<30) && y > (1 << 30))
		return ((x >> 30)*((y << 30) % Modulus) + y*(x & ((1 << 30) - 1))) % Modulus;
	ull z = x*y;
	if (z >= Modulus)
		z %= Modulus;
	return z;
}

int main() {
    ull sum = 0,tmp,res,e;
    int n;
    cin >> n;
    for(ull i  = 1; i <= n; ++i){
        tmp = i;
        res = 1;
        e = i;
        while(tmp){
            if(tmp & 1) res = modMul(res, e);
            e = modMul(e, e);
            tmp >>= 1;
        }
        //cout << res << endl;
        sum = (sum + res) % Modulus;
    }
    cout << sum << endl;
    
    return 0;
}

