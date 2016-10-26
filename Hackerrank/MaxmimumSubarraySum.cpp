#include<bits/stdc++.h>
using namespace std;
long long arr[100000];
long long sum[100001];
int main(){
    freopen("MSS.in","r",stdin);
    freopen("MSS.out","w",stdout);
    int n,k;
    int max_sum = 0;
    int q;
    cin >> q;
    while(q--){
        max_sum = 0;
        cin >> n;
        cin >> k;
        for(int i =0; i < n; i++){
            cin >> arr[i];
            sum[i+1] += (sum[i] + arr[i]);
        }
        long long tmp =0;
        for(int i = 1; i <= n;i++){
            for(int j = 0; j <= n-i; j++){
                tmp = sum[j+i] - sum[j];
                tmp %= k;
                if(tmp > max_sum ){
                      max_sum = tmp;
                }
            }
        }
        cout << max_sum << endl;
    }
    return 0;
}
