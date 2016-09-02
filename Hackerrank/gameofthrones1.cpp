#include <map>
#include <iostream>
#include <string>
using namespace std;


int main() {

    string s;
    cin>>s;
    map<char,int> chk;
    int flag = 0;
    for(int i = 0; i < s.length(); i++ )
        chk[s[i]]++;
    for(auto i : chk){
        if(i.second%2==1)
           flag++;
    }
    if(flag>1)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
