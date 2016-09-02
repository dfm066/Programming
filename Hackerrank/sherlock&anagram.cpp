#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int pairs,cnt;
    string s,sub;
    unordered_map<string,int> sub_str;
    cin>>n;
    while(n--){
        cin>>s;
        pairs = 0;
        for(int len  = 1; len < s.length(); len++){
            sub_str.clear();
            for(int i = 0; i+len-1 < s.length(); i++){
                sub = s.substr(i,len);
                sort(sub.begin(),sub.end());
                sub_str[sub]++;
            }
            for(auto i:sub_str){
                if(i.second > 1)
                    pairs += i.second*(i.second-1)/2;
            }
        }
        cout<<pairs<<endl;
    }
    return 0;
}
