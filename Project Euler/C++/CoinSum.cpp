#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
typedef unsigned long long ull;

#define MOD 1000000007

int main(){
    int T,N,ignore;
    vector<int> coins{1, 2, 5, 10, 20, 50, 100, 200};
    ull ways[100001];
    ways[0] = 1;
    for(const auto& coin : coins){
        for(auto j = coin; j <= 100000; ++j)
            ways[j] = (ways[j] % MOD + ways[j - coin] % MOD) % MOD;
    }
    ignore = scanf("%d",&T);
    while(T--){
        ignore = scanf("%d",&N);
        ignore = printf("%llu\n",ways[N]);
    }
    return 0;
}