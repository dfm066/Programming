#include "../Library/C++/utils.h"
using namespace std;

bool is_palindrome(const string &&S) {
    int len = S.size();
    int lim = len >> 1;
    len--;
    for (int i = 0; i < lim; i++) {
        if (S[i] != S[len-i])   return false;
    }
    return true;
}
bool solve(string &S) {
    int fr_map[26] = {0};
    int allowed = 0;
    int len = S.size();
    if (len & 1)    allowed = 1;
    for (auto ch : S) {
        fr_map[ch-'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (fr_map[i] & 1)  allowed--;
    }
    if (allowed < 0)    return false;
    
    for (int i = 0; i < len-1; i++) {
        if (is_palindrome(S.substr(i+1, len-i-1) + S.substr(0, i+1)))   return true;
    }
    return false;
}

int main() {
    int T;
    string S;
    cin >> T;
    while(T--) {
        cin>>S;
        if (solve(S)) {
            cout << "YES" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}