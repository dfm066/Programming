#include <bits/stdc++.h>

using namespace std;

// Structure which will store both 
// array elements and queries. 
struct node {
	int pos;
	int l;
	int r;
	int val;
};

// Boolean comparator that will be used 
// for sorting the structural array. 
bool comp(node a, node b)
{
	// If 2 values are equal the query will 
	// occur first then array element 
	if (a.val == b.val)
		return a.l > b.l;

	// Otherwise sorted in descending order. 
	return a.val > b.val;
}

// Updates the node of BIT array by adding 
// 1 to it and its ancestors. 
void update(int* BIT, int n, int idx)
{
	while (idx <= n) {
		BIT[idx]++;
		idx += idx & (-idx);
	}
}
// Returns the count of numbers of elements 
// present from starting till idx. 
int query(int* BIT, int idx)
{
	int ans = 0;
	while (idx) {
		ans += BIT[idx];

		idx -= idx & (-idx);
	}
	return ans;
}

// Complete the insertionSort function below.
long long insertionSort(vector<int> arr) {
	size_t n = arr.size();
	// create node to store the elements 
		// and the queries 
	node* a = new node[n + n+1]();

	// traverse for all array numbers 
	for (size_t i = 1; i <= n; ++i) {
		a[i].val = arr[i - 1];
		a[i].pos = 0;
		a[i].l = 0;
		a[i].r = i;
	}

	// iterate for all queries 
	for (size_t i = n + 1; i <= n + n; ++i) {
		a[i].pos = i - n;
		a[i].val = arr[i - n - 1];
		a[i].l = 1;
		a[i].r = i - n - 1;
	}

	// In-built sort function used to 
	// sort node array using comp function. 
	sort(a + 1, a + n + n + 1, comp);

	// Binary Indexed tree with 
	// initially 0 at all places. 
	int* BIT = new int[n+1]();

	// For storing answers for each query( 1-based indexing ). 
	int* ans = new int[n+1]();

	// traverse for numbers and query 
	for (size_t i = 1; i <= n + n; ++i) {
		if (a[i].pos != 0) {

			// call function to returns answer for each query 
			int cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1);

			// This will ensure that answer of each query 
			// are stored in order it was initially asked. 
			ans[a[i].pos] = cnt;
		}
		else {
			// a[i].r contains the position of the 
			// element in the original array. 
			update(BIT, n, a[i].r);
		}
	}
	long long sol = 0;
	// Output the answer array 
	for (size_t i = 1; i <= n; ++i) {
		sol += ans[i];
        cout << ans[i] << " ";
	}
    cout << endl;
	return sol;
}

int main()
{
    int t;
    cin >> t;
    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
           cin >> arr[i];
        }

        long long result = insertionSort(arr);

        cout << result << "\n";
    }
    return 0;
}