#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    if (x % y == 0) return y;
    return gcd(y, x % y);
}

int gcd_reduce(int x, int y) {
    while (x != 1) {
        int gcd_val = gcd(x, y);
        if (gcd_val == 1)   break;
        x /= gcd_val;
    }
    return x;
}

bool common_prime_divisors(int x, int y) {
    int gcd_val = gcd(x, y);
    x = gcd_reduce(x, gcd_val);
    y = gcd_reduce(y, gcd_val);
    return x == 1 && y == 1;
}

int solution(vector<int> &A, vector<int> &B) {
    int ans = 0;
    size_t len = A.size();
    for (size_t i = 0; i < len; i++) {
        if (common_prime_divisors(A[i], B[i]))  ans++;
    }
    return ans;
}

int main(){
    int Z;
    cin>>Z;
    vector<int> A, B;
    int num1, num2;
    for(int i = 0; i < Z; i++){
        cin>>num1>>num2;
        A.push_back(num1);
        B.push_back(num2);
    }
    cout << "Solution : " << solution(A,B) << endl;
    return 0;
}