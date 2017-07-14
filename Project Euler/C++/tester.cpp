#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define mod 10000
int main(){
	int n, k, N;
	unsigned int p2, p1, p0;
	unsigned int s2, s1, s0;
	unsigned int t2, t1, t0;
	scanf("%d",&N);
	// s = 0
	s2 = s1 = s0 = 0;
	for( n=1 ; n<=N ; n++ ){
	    	// p = 1
		p2 = p1 = 0; p0 = 1;
		for( k=1 ; k<=n ; k<<=1 );
		while( k>>=1 ){
		    	// p *= p
			t0 = p0*p0;
			t1 = 2*p0*p1 + t0/mod;
			t2 = 2*p0*p2 + p1*p1 + t1/mod;
			p0 = t0%mod;
			p1 = t1%mod;
			p2 = t2%mod;
			if( n&k ){
				// p *= n
				t0 = p0*n;
				t1 = p1*n + t0/mod;
				t2 = p2*n + t1/mod;
				p0 = t0%mod;
				p1 = t1%mod;
				p2 = t2%mod;
			}
		}
		// s += p
		t0 = p0+s0;
		t1 = p1+s1 + t0/mod;
		t2 = p2+s2 + t1/mod;
		s0 = t0%mod;
		s1 = t1%mod;
		s2 = t2%mod;

	}
	printf("ex48: %d%04d%04d\n", s2%100, s1, s0);
}
