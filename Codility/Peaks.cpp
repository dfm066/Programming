#include <bits/stdc++.h>
using namespace std;

int is_prime(int N) {
    if (N % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(N); i+=2) {
        if (N % i == 0) return 0;        
    }
    return 1;
}

void get_factors(int N, vector<int> &factors) {
    factors.push_back(1);
    factors.push_back(N);
    if (N % 2 == 0) {
        factors.push_back(2);
        factors.push_back(N/2);
    }
    int limit = sqrt(N);
    for (int i = 3; i <= limit; i++) {
        if (N % i == 0) {
            factors.push_back(i);
            factors.push_back(N/i);
        }
    }
    if (limit * limit == N) factors.pop_back();
    sort(begin(factors), end(factors));
    return;
}

int solution(vector<int> &A) {
    int N = A.size();
    if (N < 3)  return 0;
    vector<int> peaks(N);
    int tot_peaks = 0;
    peaks[0] = 0;
    for (int i = 1; i < N-1; i++) {
        if (A[i] > A[i-1] && A[i] > A[i+1]) {
            tot_peaks++;
            peaks[i] = tot_peaks;
            i++;
        }
        peaks[i] = tot_peaks;
    }
    peaks[N-1] = peaks[N-2]; 
    if (tot_peaks == 0)    return 0;
    if (is_prime(N) || tot_peaks == 1)   return 1;
    
    vector<int> factors;
    factors.reserve(16);
    get_factors(N, factors);
    int p_i = 0, f_i = 0, tot_f = factors.size();
    int blocks = 0, block_len = 0;
    while(peaks[p_i++] != 1);
    block_len = p_i;
    while(factors[f_i] < block_len) f_i++;
    block_len = factors[f_i];
    p_i = block_len - 1;
    while(p_i != N-1) {
        if (peaks[p_i+block_len] - peaks[p_i]) p_i += block_len;
        else {
            if (++f_i < tot_f-1) {
                block_len = factors[f_i];
                p_i = (p_i + 1) / block_len * block_len - 1;
            } else {
                return 1;
            }
        }
    }
    while ((N / factors[f_i] > tot_peaks)  && ++f_i < tot_f);
    block_len = factors[f_i];
    blocks = N / block_len;
    return blocks;
}


// int solution(vector<int> &A) {
//     int N = A.size();
//     vector<int> peaks(N);
//     int blocks = 0;
//     int tot_peak = 0, p_i = 0;
//     for (int i = 1; i < N-1; i++) {
//         if (A[i] > A[i-1] && A[i] > A[i+1]) {
//             peaks[p_i++] = i;
//             i++;
//         }
//     }
//     if (p_i == 0)   return 0;
//     if (p_i == 1)   return 1;
//     tot_peak = p_i;
//     int max_diff = 0;
//     for (int i = 1; i < tot_peak; i++) {
    
//         max_diff = max(max_diff, peaks[i] - peaks[i-1]);
//     }
//     blocks = max_diff;
//     blocks = max(blocks, peaks[0] + 1);
//     blocks = max(blocks, N - peaks[p_i-1]);
//     blocks = max(blocks, N / tot_peak);
//     if (is_prime(N)) return 1;
//     while(N % blocks != 0 && blocks < N) {
//         blocks++;
//     }
//     if (N / blocks <= tot_peak) {
//         blocks = N / blocks;
//     }
    
//     return blocks;
// }
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << solution(A) << endl;
    return 0;
}