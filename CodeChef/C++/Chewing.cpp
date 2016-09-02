<<<<<<< HEAD
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#define gc getchar
#define fors(i,s) for(int i = 0; i < s.length(); i++)
#define fori(i,n) for(int i = 0; i < n; i++)
#define ll long long
ll gum[100001];
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
	int N,K;
	scanint(N);
	scanint(K);
	int tmp;
	fori(i,N)
	{
		scanint(tmp);
		gum[i]=tmp;
	}
	ll comb = 0;
	sort(gum,gum+N);
	for(int i = 0,j = N-1;i<j;)
	{
	    if(gum[j]+gum[i]<K){
            comb += j-i;
            i++;
	    }
	    else
            j--;
	}
	cout<<comb;
	return 0;
}
=======
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#define gc getchar
#define fors(i,s) for(int i = 0; i < s.length(); i++)
#define fori(i,n) for(int i = 0; i < n; i++)
#define ll long long
ll gum[100001];
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
	int N,K;
	scanint(N);
	scanint(K);
	int tmp;
	fori(i,N)
	{
		scanint(tmp);
		gum[i]=tmp;
	}
	ll comb = 0;
	sort(gum,gum+N);
	for(int i = 0,j = N-1;i<j;)
	{
	    if(gum[j]+gum[i]<K){
            comb += j-i;
            i++;
	    }
	    else
            j--;
	}
	cout<<comb;
	return 0;
}
>>>>>>> origin/master
