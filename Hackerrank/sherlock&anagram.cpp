<<<<<<< HEAD
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
=======
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool check_anagram(string s1,string s2){
    unordered_map<char,int> m1,m2;
    if(s1.length()!=s2.length())
        return false;
    else{
        int limit = s1.length();
        for(int i = 0;i < limit; i++){
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        if(m1.size()!=m2.size())
            return false;
        else{
            for(auto i:m1){
                if(i.second!=m2[i.first])
                    return false;
            }
        }
    }
    return true;
}
int main() {
    int n;
    int pairs;
    string s;
    vector<string> arr;
    cin>>n;
    while(n--){
        cin>>s;

        pairs = 0;
        for(int k = 1; k < s.length(); k++){
            arr.clear();
            for(int i = 0; i < s.length()-k-1; i++){
               arr.push_back(s.substr(i,k));
            }
            for(auto i:arr){
                cout<<i<<" ";
            }
            cout<<endl;
            for(int i = 0; i < arr.size()-1; i++){
                for(int j = i+1; j < arr.size(); j++){
                    if(check_anagram(arr[i],arr[j]))
                        pairs++;
                }
            }
        }
        cout<<pairs<<endl;
    }
    return 0;
}
>>>>>>> origin/master
