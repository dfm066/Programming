#include "../Library/C++/utils.h"
using namespace std;

bool check_for_k(const vector<int> &peaks, const int k) {
    // Precondition k > 2
    int sz = peaks.size();
    int cnt = 2;
    int f_last = peaks[0], r_last = peaks[sz-1];
    int f_it = 1, r_it = sz-2;
    for (; f_it <= r_it; f_it++, r_it--) {
        if (peaks[f_it] - f_last >= k) {
            cnt++;
            f_last = peaks[f_it];
        }
        if (r_last - peaks[r_it] >= k) {
            cnt++;
            r_last = peaks[r_it];
        }
    }
    
    if (r_last - f_last < k || r_last == f_last)    cnt--;
    if (cnt >= k)   return true;
    return false;
}

int solution(vector<int> &A) {
    vector<int> peaks;
    int N = A.size();

    peaks.reserve((N-1)/2 + 1);

    for (int it = 1; it < N-1; it++) {
        if (A[it] > A[it-1] && A[it] > A[it+1]) {
            peaks.push_back(it);
            it++;
        }
    }

    int sz = peaks.size();
    if (sz <= 2)    return sz;

    int lim = (1 + ceil(sqrt(1+4*(peaks[sz-1] - peaks[0])))) / 2;
    for (int k = lim; k > 2; k--) {
        if(check_for_k(peaks, k))   return k;
    }
    return 2;
}