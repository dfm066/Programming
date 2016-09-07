#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> primes;
    int p = 2;
    int limit = 1000000;
    bool flg[1000001];
    for(p = 2; p <= limit;){
        primes.push_back(p);
        for(int j = 1; p*j <= limit; flg[p*j]=true,j++);
        for(;p <= limit && flg[p]== true; p++);
    }
    for(auto i:primes){
        cout << i << " ";
    }
    cout << endl<< sqrt(99999999997) ;
    return 0;
}
