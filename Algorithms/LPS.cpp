#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int len = s.length();
    int ps[len][len];
    for(int i = 0; i < len; i++)
        for(int j = 0; j < len; j++)
            ps[i][j] = 1;
    for(int l = 2; l <= len; l++){
        for(int i = 0,j; i <= len-l; i++){
            j = i + l - 1;
            if(s[i] == s[j] && l == 2)
                ps[i][j] =  2;
            else if(s[i] == s[j])
                ps[i][j] = ps[i+1][j-1] + 2;
            else
                ps[i][j] = max(ps[i][j-1],ps[i+1][j]);
        }
    }
    for(int i = 0 ; i < len; i++){
        for(int j = 0; j < len; j++)
            cout << ps[i][j] << " ";
        cout << endl;
    }
    cout << ps[0][len-1] << endl;
    return 0;
}
