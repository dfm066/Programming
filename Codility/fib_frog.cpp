//  The Fibonacci sequence is defined using the following recursive formula:
    //  F(0) = 0
    //  F(1) = 1
    //  F(M) = F(M - 1) + F(M - 2) if M >= 2
//  A small frog wants to get to the other side of a river. The frog is initially located at one bank of the river (position −1) and wants to get to the other bank (position N). The frog can jump over any distance F(K), where F(K) is the K-th Fibonacci number. Luckily, there are many leaves on the river, and the frog can jump between the leaves, but only in the direction of the bank at position N.
//  The leaves on the river are represented in an array A consisting of N integers. Consecutive elements of array A represent consecutive positions from 0 to N − 1 on the river. Array A contains only 0s and/or 1s:
//  0 represents a position without a leaf;
//  1 represents a position containing a leaf.
//  The goal is to count the minimum number of jumps in which the frog can get to the other side of the river (from position −1 to position N). The frog can jump between positions −1 and N (the banks of the river) and every position containing a leaf.
//  For example, consider array A such that:
    //  A[0] = 0
    //  A[1] = 0
    //  A[2] = 0
    //  A[3] = 1
    //  A[4] = 1
    //  A[5] = 0
    //  A[6] = 1
    //  A[7] = 0
    //  A[8] = 0
    //  A[9] = 0
    //  A[10] = 0
//  The frog can make three jumps of length F(5) = 5, F(3) = 2 and F(5) = 5.
//  Write a function:
//  def solution(A)
//  that, given an array A consisting of N integers, returns the minimum number of jumps by which the frog can get to the other side of the river. If the frog cannot reach the other side of the river, the function should return −1.
//  For example, given:
    //  A[0] = 0
    //  A[1] = 0
    //  A[2] = 0
    //  A[3] = 1
    //  A[4] = 1
    //  A[5] = 0
    //  A[6] = 1
    //  A[7] = 0
    //  A[8] = 0
    //  A[9] = 0
    //  A[10] = 0
//  the function should return 3, as explained above.
//  Write an efficient algorithm for the following assumptions:
//  N is an integer within the range [0..100,000];
//  each element of array A is an integer that can have one of the following values: 0, 1.

#include <iostream>
#include <vector>
#include <algorithm>
#include "Library/C++/utils.h"
#include <assert.h>

using namespace std;

int solution(vector<int> &A);

int main() {
    std::mt19937 gen;
 
    // Seed the engine with an unsigned int
    gen.seed(1);
    int N = 5000;
    vector<int> A(N);
    std::generate(A.begin(), A.end(), [&gen]() {return gen()&1;});
    auto st = GET_HRTIME();
    cout << solution(A) << endl;
    auto en = GET_HRTIME();
    fmt::print("Execution Time : {}ms\n", ms(en-st).count());
    return 0;
}

vector<int> fibs2n(int n) {
    vector<int> fibs;
    int f1 = 1, f2 = 1;
    while (f2 <= n) {
        fibs.emplace_back(f2);
        f2 = f1 + f2;
        f1 = f2 - f1;
    }
    
    return fibs;
}

int solution(vector<int> &A) {
    if (A.size() == 0) return 1;
    int N = A.size();
    vector<int> fibs = fibs2n(N+1);
    vector<int> leaf_pos;
    leaf_pos.reserve(N/4);
    leaf_pos.emplace_back(-1);
    for (int i = 0; i < N; ++i) if(A[i] == 1) leaf_pos.emplace_back(i);
    leaf_pos.emplace_back(N);
    vector<int> dp(N+2, N+1);
    for (int i = leaf_pos.size()-2; i > 0; --i) dp[leaf_pos[i]] = N+1;
    dp[N] = 0;
    dp[N+1] = N + 1;
    for (int i = int(leaf_pos.size())-1; i > 0; --i) {
        if (dp[leaf_pos[i]] == N+1) continue;
        for (int j = 0; j < int(fibs.size()); ++j) {
            int pos = leaf_pos[i]-fibs[j];
            if ((pos >= 0 && A[pos])) dp[pos] = min(dp[leaf_pos[i]] + 1, dp[pos]);
            if (pos == -1) dp[N+1] = min(dp[leaf_pos[i]] + 1, dp[N+1]);
        }
    }
    if (dp[N+1] == N+1) return -1;
    return dp[N+1];
}