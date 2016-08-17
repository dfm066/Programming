#include <cstdio>
#include <iostream>
#include <string>
#define fors(i,s) for(int i = 0; i < s.length(); i++)
#define fori(i,n) for(int i = 0; i < n; i++)
using namespace std;
int arr[1000001];
int main(){
    int t,n,b,f;
    unsigned long long max_sum;
    scanf("%d",&t);
    int max_len = 0;
    while(t--){
        scanf("%d",&n);
        max_sum =b=f= 0;
        max_len = n;
//        cout<<max_len<<endl;
        fori(i,n){
            scanf("%d",&arr[i]);
            max_sum += arr[i];
            arr[i] = max_sum;
        }
        if(max_sum%2!=0){
            fori(i,n-1){
                if(arr[i]%2!=0){
//                    cout<<arr[i]<<" "<<i<<" "<<max_len<<endl;
                    b = n-1-i;
                    break;
                }
            }
            for(int i = n-1; i >=0 ; i-- ){
                if(arr[i]%2==0){
                    f = i+1;
                    break;
                }
            }
            max_len = b>f?b:f;
        }
        cout<<max_len<<endl;
    }
}
