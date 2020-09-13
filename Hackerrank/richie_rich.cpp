#include <map>
#include <set>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int changes[100000];
int main(){
    int n;
    int k;
 //   freopen("richie_input.txt","r",stdin);
 //   freopen("richie_output.txt","w",stdout);
    cin >> n >> k;
    string number;
    cin >> number;
    if(n<=k){
        for(int i = 0;i < n; i++){
            cout<<9;
        }
        cout<<endl;
        return 0;
    }
    int cnt = 0;
    int tmp,index;
    for(int i = 0,j = n-1; i<j;j--,i++){
        if(number[i]!=number[j]){
            cnt++;
            if(number[i]>number[j]){
                number[j] = number[i];
                changes[j] = 1;
            }
            else{
                number[i] = number[j];
                changes[i] = 1;
            }
        }
    }
    if(cnt>k){
        cout<<"-1"<<endl;
        return 0;
    }
    else{
        int allowed = k - cnt;
        for(int i = 0;allowed>0&&i<=n/2;i++){
            if(number[i]!='9'){
                if(changes[i]==1||changes[n-1-i]==1){
                    number[i]='9';
                    number[n-1-i]='9';
                    allowed--;
                }
                else if(changes[i]==0&&changes[n-1-i]==0&&allowed>1){
                    number[i]='9';
                    number[n-1-i]='9';
                    allowed-=2;
                }
                else{
                    number[n/2]='9';
                    allowed--;
                }
            }
        }
        cout<<number<<endl;
    }


    return 0;
}
