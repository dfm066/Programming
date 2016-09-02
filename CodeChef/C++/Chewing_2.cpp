#include<iostream>
#include <cmath>
#include<cstdio>
#include <algorithm>
#include <vector>
#define gc getchar

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
	int i,j,tmp;
	register int x;
	long long cnt=0;
	vector<int> vec;
	for(i=0;i<N;++i)
	{
		scanint(tmp);
		if(tmp<K)
		{
			vec.push_back(tmp);
		}
	}
	int size=vec.size();
	int t_c = 0,rep;
	sort(vec.begin(),vec.begin()+size);
	for(i=0;i<size-1;++i)
	{
	    for(rep = 1;vec[i+rep]==vec[i];rep++);
        i+=rep-1;
        t_c = 0;
		x=(K-vec[i]);
		for(j=i+1;j<size;++j)
		{
			if(vec[j]<x)
				t_c++;
			else
				break;
		}
		cnt += (long long)rep*t_c;
		if(2*vec[i]<K)
            cnt += rep-1;
	}
	cout<<cnt;
	return 0;
}
