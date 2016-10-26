#include<bits/stdc++.h>
using namespace std;
int arr[100000];
int sum[100001];
int main(){
    int n,k;
    int max_sum = 0;
    int index[2];
    int cnt = 0;
    cin >> n;
    cin >> k;
    for(int i =0; i < n; i++){
        cin >> arr[i];
        sum[i+1] += sum[i] + arr[i];
    }
    if(sum[n] < k)
        cnt = n*(n+1)/2;
    else{
        int tmp =0;
        for(int i = 1; i < n;i++){
            for(int j = 0; j <= n-i; j++){
                tmp = sum[j+i] - sum[j];
                if(tmp < k ){
                    cnt++;
//                    max_sum = tmp;
//                    index[0] = j;
//                    index[1] = j+i-1;
                }
            }
        }
    }
    cout << cnt << endl;
 //   cout << index[0] << " "<< index[1] << endl;
    return 0;
}
