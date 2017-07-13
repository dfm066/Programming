#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 5000000
int p[MAX+1];
int maxp[MAX+1];

int main() {
    for(int i = 0; i < MAX+1; ++i) p[i] = 0;
    for(int c = 5; c < MAX/2 + 1; ++c){
        for(int b = 4; b < c; ++b){
            int sum = b+c;
            for(int a = 1; a < b; ++a){
                ++sum; 
                if(sum < MAX+1 && a*a + b*b == c*c)
                    p[sum] += 1;
            }
        }
    }
    int curr_max,curr_cnt;
    curr_max = curr_cnt = 0;
    for(int i = 12; i < MAX+1; ++i){
        if(curr_cnt < p[i]){
            curr_cnt = p[i];
            curr_max = i;
        }
        maxp[i] = curr_max;
    }
	printf("Finished");
    int T,N;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        printf("%d\n",maxp[N]);
    }
    
    return 0;
}