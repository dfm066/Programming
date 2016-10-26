#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];
int len[1000001];

int main() {
    freopen("lis.in","r",stdin);
    int N,max_len;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    max_len = 1;
    int j;
    len[max_len] = arr[0];
    for(int i = 1; i < N; i++){
        for(j = max_len; j >= 0; j--){
            if(len[j] < arr[i]){
                len[j+1] = arr[i];
                break;
            }
        }
        if(j == max_len)
            max_len++;
    }
//    cout << endl;
//    for(int i = 1; i <= max_len; i++){
//        cout << len[i] << endl;
//    }
    cout << endl << max_len << endl;
    return 0;
}
