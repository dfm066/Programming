#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n,m;
    scanf("%d",&t);
    while(t--){
       scanf("%d%d",&n,&m);
        if((m==1)||(n%2==0))
            printf("2\n");
        else
            printf("1\n");
    }
    return 0;
}
