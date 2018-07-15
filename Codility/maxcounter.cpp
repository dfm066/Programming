#include <vector>
using namespace std;

vector<int> solution(int N, vector<int> &A) {
    vector<int> res(N);
    int M = (int)A.size();
    int max = 0, curr_max = 0;
    for(int i = 0 ; i < M; i++){
        if(A[i] <= N){
            if(res[A[i]-1] < max)   res[A[i]-1] = max;
            if(++res[A[i]-1] > curr_max) {
                    curr_max = res[A[i]-1];
            }
        }else {
            max = curr_max;
        }
    }
    for(int i = 0; i < N; i++) {
        if (res[i] < max)   res[i] = max;
    }
    return res;
}