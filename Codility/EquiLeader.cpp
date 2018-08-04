#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    int N = (int)A.size();
    unordered_map<int, int> left_hist, right_hist;
    int curr_lead = -1;
    int curr_cnt = 0;
    vector<int> left_lead(N), right_lead(N);
    left_hist.reserve(N);
    right_hist.reserve(N);
    for(int i = 0; i < N; i++) {
        curr_cnt = left_hist[A[i]]++;
        if (++curr_cnt > (i+1) / 2) {
           curr_lead = i; 
        } else if (curr_lead == -1 ||
                   left_hist[A[curr_lead]] <= (i+1) / 2) {
            curr_lead = -1;
        }
        left_lead[i] = curr_lead;
    }
    
    for(int i = N-1; i >= 0; i--) {
        curr_cnt = right_hist[A[i]]++;
        if (++curr_cnt > (N-i) / 2) {
           curr_lead = i; 
        } else if (curr_lead == -1 || 
                   right_hist[A[curr_lead]] <= (N-i) / 2) {
            curr_lead = -1;
        }
        right_lead[i] = curr_lead;
    }
    int equi_idx = 0;
    for (int i = 0; i < N-1; i++) {
        if (left_lead[i] == -1 || right_lead[i+1] == -1)  continue;
        if(A[left_lead[i]] == A[right_lead[i+1]]) {
           
            equi_idx++;
        }
    }
   
    return equi_idx;
}