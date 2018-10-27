<<<<<<< HEAD
#include <cstdio>
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
void scanll(long long &x)
{
	register int c = gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main(){
    long long n,m,cuts;
	int t;
	scanint(t);
	while(t--){
        scanll(n);
        scanll(m);
        cuts = n * m - 1;
        if(cuts%2==0)
            printf("No\n");
        else
            printf("Yes\n");
	}
	return 0;
}
=======
#include <cstdio>
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
void scanll(long long &x)
{
	register int c = gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main(){
    long long n,m,cuts;
	int t;
	scanint(t);
	while(t--){
        scanll(n);
        scanll(m);
        cuts = n * m - 1;
        if(cuts%2==0)
            printf("No\n");
        else
            printf("Yes\n");
	}
	return 0;
}
>>>>>>> origin/master
