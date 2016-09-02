#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin>>T;
    string s;
    for(int i = 0; i < T; i++){
        cin>>s;
        int j = s.size()-1;
        for(; j >= 0; j--){
            int k = j-1;
            for(; k>=0; k--){
                if(s[k]<s[j]){
                    swap(s[k],s[j]);
                    break;
                }
            }
            if(k>=0){
                if(s.length()-1-k<1){
                    cout<<s<<endl;
                    break;

                }
                else{
                    sort(s.begin()+k+1,s.end());
                    cout<<s<<endl;
                    break;
                }
           }
        }
        if(j<0)
            cout<<"no answer"<<endl;


    }
    return 0;
}
