#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define LIMIT 1000000

long long fact(int n) {
    long long f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

long long nCr(int no) {
    long long N = 1;
    long long D = 1;
    int cnt = 0;
    for (int r = 3; r <= no/2; r++) {
        N = no;
        int j = r;
        for (int i = 1; i < j; i++)  N *= (no-i);
        D = fact(r);
        if (N/D > LIMIT) cnt += 2;
    }
    if (cnt && no % 2 == 0) cnt -= 1;
    return cnt;
}

int main()  {
    long long gt_val = 0;
    long long curr_val = 0;
    for (int i = 23; i <= MAX; i++) {
        gt_val += nCr(i);
    }
    cout << " Count : " << gt_val << endl;
    return 0;
}