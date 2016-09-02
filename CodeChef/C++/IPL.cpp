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
int arr[200001];
int main(){
    int N;
    ll m = 0;
    scanint(N);
    fori(i,N){
        scanint(arr[i]);
        m += arr[i];
        arr[i]+= min(min(arr[i-1],arr[i-2]),arr[i-3]);
    }
    if(N>2)
        cout<<m-min(min(arr[N-1],arr[N-2]),arr[N-3]);
    else
        cout<<m;
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
int arr[200001];
int main(){
    int N;
    ll m = 0;
    scanint(N);
    fori(i,N){
        scanint(arr[i]);
        m += arr[i];
        arr[i]+= min(min(arr[i-1],arr[i-2]),arr[i-3]);
    }
    if(N>2)
        cout<<m-min(min(arr[N-1],arr[N-2]),arr[N-3]);
    else
        cout<<m;
    return 0;
}
>>>>>>> origin/master
