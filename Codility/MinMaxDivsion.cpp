#include <numeric>
#include <algorithm>

int isValid(const vector<int> &A, int K, const int &target) {
    int pos = 0;
    int prev = 0;
    while(K > 0) {
        if (pos == int(A.size())) return 1;
        int curr = distance(begin(A), lower_bound(begin(A)+pos, end(A), prev+target+1));
        if (curr > 0 && A[curr-1]-prev <= target) K--;
        else if (curr == 0) return -1;
        prev = A[curr-1];
        pos = curr;
    }
    if (pos != int(A.size())) return -1;
    return 0;
}

int solution(int K, int M, vector<int> &A) {
    int N = A.size();
    int maxel = *max_element(begin(A), end(A));
    if (K >= N) return maxel;
    int tot = accumulate(begin(A), end(A), 0);
    if (K == 1) return tot;
    for (int i = 1; i < N; ++i) A[i] += A[i-1];
    A.erase(unique(begin(A), end(A)), end(A));
    int low = 1, high = tot, mid = 0;
    vector<int> valid;
    while (low <= high) {
        mid = (low + high) / 2;
        int res = isValid(A, K, mid);
        if (res  >= 0) {
            valid.emplace_back(mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return *min_element(begin(valid), end(valid));
}