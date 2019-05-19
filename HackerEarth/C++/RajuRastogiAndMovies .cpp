#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> F(N);
    for (int i = 0; i < N; i++) {
        cin >> F[i];
    }
    
    sort(begin(F), end(F));
    vector<int> prefix(N);
    prefix[N-1] = F[N-1];
    for (int i = N-2; i > 0; i--) {
        prefix[i] = F[i] + prefix[i+1];
    }
    int st = 0;
    int en = N-1;
    int mid;
    int solved;
    int Y;
    while (st < en) {
        mid = (st + en)/2;
        Y = F[mid];
        solved = prefix[mid+1] - Y*(N-1-mid);
        if (solved >= X) break;
        else en = mid-1;
    }
    int ans_st = mid;
    while (st <= en) {
        st = mid+1;
        mid = (st + en)/2;
        Y = F[mid];
        solved = prefix[mid+1] - Y*(N-1-mid);
        if (solved < X) break;
    }
    int ans_en = mid;
    Y = F[ans_en];
    while(ans_st <= ans_en) {
        solved = prefix[ans_en+1] - Y*(N-1-ans_en);
        if (solved >= X) break;
        Y--;
        while( Y < F[ans_en]) ans_en--;
    }
    assert(ans_st <= ans_en);
    cout << Y << endl;
    return 0;
}
