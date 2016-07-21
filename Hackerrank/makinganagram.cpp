#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define fors(i,s) for(int i = 0; i < s.length(); i++)
#define fori(i,n) for(int i = 0; i < n; i++)
using namespace std;


int main() {
    string s1,s2;
    cin>>s1>>s2;
    int chk[2][26]={0};
    fors(i,s1){
        chk[0][s1[i]-'a']++;
    }
    fors(i,s2){
        chk[1][s2[i]-'a']++;
    }
    int ans=0;
    fori(i,26){
        ans+=abs(chk[0][i]-chk[1][i]);
    }
    fori(i,26){
        cout<<chk[0][i]<<"\t"<<chk[1][i]<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
