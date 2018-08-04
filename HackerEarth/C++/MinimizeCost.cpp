#include <bits/stdc++.h>
using namespace std;

// void print_vec(string msg, const vector<int> &vec) {
//     cout << msg;
//     for (auto val:vec)  {
//         cout << val << " ";
//     }
//     cout << endl;
// }

long long Solve(int n, long long k, vector<int> &arr, const vector<int> &positive, const vector<int> &negative)
{
  
    int pos = 0, neg = 0;
    // print_vec("Positive vec : ", positive);
    // print_vec("Negative vec : ", negative);
    while (positive[pos] != -1 && negative[neg] != -1) {
        if (abs(positive[pos] - negative[neg]) <= k) {
            if (arr[positive[pos]] > (-1 * arr[negative[neg]])) {
                arr[positive[pos]] += arr[negative[neg]];
                arr[negative[neg++]] = 0;
            } else if (arr[positive[pos]] < (-1 * arr[negative[neg]])) {
                arr[negative[neg]] += arr[positive[pos]];
                arr[positive[pos++]] = 0;
            } else {
                arr[positive[pos++]] = arr[negative[neg++]] = 0;
            }
        } else if (positive[pos] > negative[neg]) {
            neg++;
        } else {
            pos++;
        }
        // print_vec("Array is : ", arr);
        // cout << pos << " " << neg << endl;
    }

    // print_vec("Array is : ", arr);
    long long res = 0;
    for (auto val:arr)  {
        res += std::abs(val);
    }
    return res;
}

int main()
{
    long long k;
    int n;
    scanf("%d",&n);
    scanf("%lld",&k);

    vector<int> arr(n);
    vector<int> positive, negative;
    positive.reserve(n+1);
    negative.reserve(n+1);
    int pos = 0, neg = 0;
    for (int i_arr = 0; i_arr < n; i_arr++)
    {
       scanf("%d",&arr[i_arr]);
        if (arr[i_arr] > 0)
        {
            positive.push_back(i_arr);
        } else if (arr[i_arr] < 0) {
            negative.push_back(i_arr);
        }
    }
    positive.push_back(-1);
    negative.push_back(-1);
    long long out_;
    out_ = Solve(n, k, arr, positive, negative);
    printf("%lld",out_);
    return 0;
}