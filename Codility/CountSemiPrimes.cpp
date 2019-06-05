#include "../Library/C++/utils.h"
using namespace std;

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    vector<int> primes = primes2n(N/2);
    vector<bool> semiprimes(N+1, false);
    vector<int> prefixsum(N+1, 0);
    int sz = primes.size();
    int M = P.size();
    vector<int> ans(M, 0);
    for (int p1 = 0; p1 < sz; p1++) {
        for (int p2 = p1; p2 < sz; p2++) {
            int val = primes[p1]*primes[p2];
            if (val > N)  break;
            semiprimes[val] = true;
        }
    }
    int cnt = 0;
    for (int it = 1; it <= N; it++) {
        if (semiprimes[it]) cnt++;
        prefixsum[it] = cnt;
    }
    for (int k = 0; k < M; k++) {
        ans[k] = prefixsum[Q[k]] - prefixsum[P[k]-1];
    }
    
    return ans;
}