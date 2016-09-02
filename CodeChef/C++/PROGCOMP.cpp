#include <cstdio>
#include <iostream>
#include <string>
#define fors(i,s) for(int i = 0; i < s.length(); i++)
#define fori(i,n) for(int i = 0; i < n; i++)
using namespace std;
#define mod 1000000007

unsigned long long facts[] = {1,1,2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 227020758, 178290591, 674358851, 789741546, 425606191, 660911389, 557316307, 146326063, 72847302, 602640637, 860734560, 657629300, 440732388, 459042011};
int arr[27];
unsigned long long ans=0;

int main(){
    int T;
    cin>>T;
    getchar();
    char ch = 0;
    while(T--){
        ans=0;
        while(1){
            ch = getchar();
            if(ch=='\n')
                break;
            arr[ch-'a']++;
        }
        fori(i,26){
            if(arr[i]!=0)
                ans++;
        }
        ans = facts[ans];
        fori(i,26){
            ans = (ans*facts[arr[i]])%mod;
            arr[i] = 0;
        }
        cout<<ans<<endl;
    }
    return 0;
}
