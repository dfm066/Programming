#include <bits/stdc++.h>
using namespace std;
int cycle[10001];
int longest[10001];
template <typename T>
void print_vector(const vector<T> &v, const string&& str) {
    cout << str;
    for(const auto &val : v) {
        cout << val << " ";
    }
    cout << endl;
}
int main(){
    int lim;
    cin >> lim;
    int rem,pos;
    vector<int> frac(lim+1,0);
    for(int d = 1; d <= lim; d++){
       frac.assign(d,0);
       rem = 1;
       pos = 0;
       while(frac[rem] == 0 && rem != 0){
            frac[rem] = pos;
            rem *= 10;
            rem %= d;
            pos++;
        }
        if(rem != 0)
            cycle[d] = pos - frac[rem];
        print_vector(frac, "Frac : ");
    }
    int curr = 0;
    for(int d = 1; d <= lim; d++){
        longest[d] = curr;
        if(cycle[d] > curr)
            curr = d;
    }
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << longest[n] << endl;
    }
    return 0;
}
