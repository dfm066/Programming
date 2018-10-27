<<<<<<< HEAD
#include <cstdio>
#include <iostream>
#include <algorithm>
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
    scanint(N);
    for (int i = 0; i < N; i++)
          scanint(arr[i]);
    ll mw = 0;
    for (int i = 0, j = N-1; i+2<j-2; i+=2,j-=2)
    {
        mw += min(arr[i],min(arr[i+1],arr[i+2]));
        mw += min(arr[j],min(arr[j-1],arr[j-2]));
    }
    if()
//    for(int i = 3; i < N; i++){
//        scanint(arr[i]);
//        arr[i]+= min(min(arr[i-1],arr[i-2]),arr[i-3]);
//    }
//    if(N>2)
//        cout<<min(min(arr[N-1],arr[N-2]),arr[N-3]);
//    else
//        cout<<0;
    cout<<mw;
    return 0;
}
=======
#include <cstdio>
#include <iostream>
#include <algorithm>
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
    scanint(N);
    for (int i = 0; i < N; i++)
          scanint(arr[i]);
    ll mw = 0;
    for (int i = 0, j = N-1; i+2<j-2; i+=2,j-=2)
    {
        mw += min(arr[i],min(arr[i+1],arr[i+2]));
        mw += min(arr[j],min(arr[j-1],arr[j-2]));
    }
    if()
//    for(int i = 3; i < N; i++){
//        scanint(arr[i]);
//        arr[i]+= min(min(arr[i-1],arr[i-2]),arr[i-3]);
//    }
//    if(N>2)
//        cout<<min(min(arr[N-1],arr[N-2]),arr[N-3]);
//    else
//        cout<<0;
    cout<<mw;
    return 0;
}
>>>>>>> origin/master
