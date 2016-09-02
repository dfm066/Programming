#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define fori(i,n) for(int i = 0; i < n; i++)
using namespace std;
bool check(unordered_map<char,int> curr, unordered_map<char,int> stable){
    for(auto i:curr){
        if(curr[i.first] < stable[i.first])
            return false;
    }
    return true;
}
int main() {
//    freopen("bearandgene.txt","r",stdin);
    string s;
    int len;
    cin >> len;
    unordered_map<char,int> gene,stable;
    cin >> s;
    int need = len/4;
    int window = len;
    for(int i = 0; i < len; i++){
        gene[s[i]]++;
    }
    for(auto i:gene){
        stable[i.first] = gene[i.first]-need > 0 ? gene[i.first]-need : 0;
        gene[i.first] = 0;
    }
    bool flg =false;
   for(int i = 0,j=0; j < len;){
        if(stable[s[j]] > 0){
            flg = true;
            gene[s[j]]++;
            if(check(gene,stable)){
                flg = false;
                while(gene[s[i]]>stable[s[i]]){
                    gene[s[i]]--;
                    i++;
                    while(stable[s[i]] == 0 and i <=j)
                        i++;
                }
                if(j - i + 1 <= window){
                    window = j-i +1;
                }
                gene[s[i]]--;
                j++;
                while(stable[s[j]] == 0 and j < len)
                    j++;
                i++;
                while(stable[s[i]] == 0 and i <= j)
                    i++;
            }
            else
                j++;
        }
        else{
            if(!flg)
                i++;
            j++;
        }
    }
    if(window==len)
        cout << 0 <<endl;
    else
        cout<<window<<endl;
    return 0;
}
