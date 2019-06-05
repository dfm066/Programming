#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

template <typename Comparable>
vector<Comparable> maxOfMinOfWindow(const vector<Comparable> &A) {
    int N = A.size();
    vector<Comparable> sol(N, 0);
    stack<Comparable> helper;
    for (int it = 0; it < N; it++) {
        while(!helper.empty() && A[helper.top()] > A[it]) {
            int prev = helper.top();
            helper.pop();
            int st = helper.empty() ? 0 : helper.top()+1;
            int window = it - st;
            sol[window - 1] = max(sol[window-1], A[prev]);
        }
        helper.push(it);
    }
    while(!helper.empty()) {
        int prev = helper.top();
        helper.pop();
        int st = helper.empty() ? 0 : helper.top()+1;
        int window = N - st;
        sol[window - 1] = max(sol[window-1], A[prev]);
    }
    for (int it = N-2; it >= 0; it--) {
        if (sol[it] < sol[it+1]) {
            sol[it] = sol[it+1];
        }
    }
    return sol;
}

int main()
 {
	int T;
	cin >> T;
	while(T--) {
	    int N;
	    cin >> N;
	    vector<int> A(N);
	    for(int i = 0; i < N; i++) {
	        cin >> A[i];
	    }
	    auto solution = maxOfMinOfWindow(A);
	    for (const auto &e : solution) {
	        cout << e << " ";
	    }
	    cout << endl;
	}
	return 0;
}