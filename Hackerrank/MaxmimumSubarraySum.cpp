#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll arr[100000];
int main() {
    ll sum,m,max,tmp_sum,tmp_mod1,tmp_mod2;
    int q,n;
    cin>>q;
    while(q--){
        cin>>n;
        cin>>m;
        sum = 0;
        max = 0;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            sum += arr[i];
        }
        max = sum % m;
        tmp_sum = sum;
        sort(arr,arr+n);
        for(int  i = 0,j = n-1; i < j;){
            tmp_mod1 = (tmp_sum-arr[i])%m;
            tmp_mod2 = (tmp_sum-arr[j])%m;
            if(tmp_mod2>tmp_mod1){
                tmp_sum -= arr[j];
                j--;
                if(tmp_mod2>max)
                    max = tmp_mod2;
            }
            else{
                tmp_sum -= arr[i];
                i++;
                if(tmp_mod1>max)
                    max = tmp_mod1;
            }

        }
        cout<<max<<endl;
    }
    return 0;
}
