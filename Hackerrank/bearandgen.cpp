#include <map>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define fori(i,n) for(int i = 0; i < n; i++)
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int len;
    char s[500001];
    scanf("%d",&len);
    gets(s);
    map<char,unsigned int> m,chk;
    int n = len/4,l=0;
    for(int i =s;i < s.length(); i++){
        m[s[i]++;
    }
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
        l+=i.second;
    }
    cout<<l<<" "<<s.length();

    return 0;
}
