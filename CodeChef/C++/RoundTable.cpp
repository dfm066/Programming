<<<<<<< HEAD
#include <cstdio>
#include <iostream>
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
int arr[1000001];
int main(){
    int N;
    scanint(N);
    fori(i,N){
        scanint(arr[i]);
        if(i>1)
            arr[i]+= min(arr[i-1],arr[i-2]);
    }
    if(N>1){
        cout<<min(arr[N-1],arr[N-2]);
    }
    else
        cout<<arr[0];
	return 0;
}
=======
#include <cstdio>
#include <iostream>
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
int arr[1000001];
int main(){
    int N;
    scanint(N);
    fori(i,N){
        scanint(arr[i]);
        if(i>1)
            arr[i]+= min(arr[i-1],arr[i-2]);
    }
    if(N>1){
        cout<<min(arr[N-1],arr[N-2]);
    }
    else
        cout<<arr[0];
	return 0;
}
>>>>>>> origin/master
