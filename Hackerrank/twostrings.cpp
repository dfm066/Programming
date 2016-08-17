#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T,j;
    string s1,s2;
    cin>>T;
    for(int i = 0; i < T; i++){
        cin>>s1>>s2;
        for(j=0;j<26;j++){
            if(s1.find(char(j+'a'))!=string::npos&&s2.find(char(j+'a'))!=string::npos){
                 cout<<"YES"<<endl;
                 break;
            }
        }
        if(j==26)
            cout<<"NO"<<endl;
    }

    return 0;
}
