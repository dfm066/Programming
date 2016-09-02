<<<<<<< HEAD
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#define fors(i,s) for(int i = 0; i < s.length(); i++)
#define fori(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define gc getchar
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int arr[65001];
int main(){
    int N,K;
    scanint(N);
    scanint(K);
    fori(i,N){
        scanint(arr[i]);
    }
    sort(arr,arr+N);
    ll var=0;
    int j;
    for(int i = 0;i < N-1; i++){
        for(j=i+1;arr[j]-arr[i]<K&&j<N;j++);
        var += N-j;
    }
    cout<<var;
	return 0;
}
=======
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#define fors(i,s) for(int i = 0; i < s.length(); i++)
#define fori(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define gc getchar
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int arr[65001];
int main(){
    int N,K;
    scanint(N);
    scanint(K);
    fori(i,N){
        scanint(arr[i]);
    }
    sort(arr,arr+N);
    ll var=0;
    int j;
    for(int i = 0;i < N-1; i++){
        for(j=i+1;arr[j]-arr[i]<K&&j<N;j++);
        var += N-j;
    }
    cout<<var;
	return 0;
}
>>>>>>> origin/master
