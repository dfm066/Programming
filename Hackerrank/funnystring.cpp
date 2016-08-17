#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T,k,j;
    cin >> T;
    string s,r;
    for(int i = 0; i < T; i++){
        cin >> s;
        for( k = 0,j=s.length()-1; k < j; k++,j--){
            if(abs(s[k]-s[k+1])!=abs(s[j]-s[j-1]))
                break;

        }
        if(k>=j)
            cout<<"Funny"<<endl;
        else
            cout<<"Not Funny"<<endl;

    }
    return 0;
}
