#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#define fors(i,s) for(int i = 0; i < s.length(); i++)
#define fori(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define gc getchar
int arr[1001];
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main(){
    int N,s;
    scanf("%d",&N);
    fori(i,N){
        scanint(s);
        arr[s]++;
    }
    ll rev = 0;
    ll tmp = 0;
    fori(i,1000){
        if(arr[i]){
            tmp = 0;
            for(int j = i+1; j< 1001; j++){
                if(arr[j]){
                    tmp += (j-i)*arr[j];
                }
            }
            rev += tmp*arr[i];
        }
    }
    printf("%lld\n",rev);
}
