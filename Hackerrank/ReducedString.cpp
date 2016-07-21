#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    cin>>s;
    int i=0;
    for(i=0; i < s.length();i++){
        if(s[i]==s[i+1]){
            s=s.erase(i,2);
            i=-1;
        }
    }
    if(s.length()==0)
        s="Empty String";
    cout<<s;
    return 0;
}
