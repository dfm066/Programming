#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    string s;
    for(int i = 0; i < T; i++){
        cin >> s;
        for(int j = 0; j < s.length()/2; j++){
            if(s[j]!=s[s.length()-1-j])
                cout<<j<<endl;
        }
    }
    return 0;
}
