#include <bits/stdc++.h>
using namespace std;
int facts[13];

void init(){
    int fact = 1;
    for(int i = 0; i < 13; i++){
        fact *= (i+1);
        facts[i] = fact;
    }
}
void next_perm(string &curr){
    int len = curr.length();
    int i =  len - 1;
    while( i > 0 and curr[i - 1] >= curr[i])
        i -= 1;
    if (i <= 0)
        return;

    int j = len - 1;
    while(curr[j] <= curr[i - 1])
        j -= 1;
    swap(curr[i - 1], curr[j]);
    int lim = (len-i)/2;
    for(int k = 0; k < lim; k++)
        swap(curr[i+k],curr[len - 1 - k]);
}
int main(){
    string s = "abcdefghijklm";
    string ans = s;
    int len = s.length();
    int t;
    int n;
    int state;
    int need;
    init();
    cin >> t;
    while(t--){
        state = 0;
        ans = s;
        cin >> n;
        need = n-1;
        while(need--)
                next_perm(ans);
        cout << ans << endl;
    }
    return 0;
}
