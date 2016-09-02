#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n,s,flg;
    scanf("%d",&t);
    while(t--){
       scanf("%d",&n);
       for(int i = 0; i < n; i++){
            scanf("%d",&s);
            if(i!=0)
                flg ^= s;
            else
                flg=s;
       }
        if(n%2==0&&flg==0)
            printf("First\n");
        else
            printf("Second\n");

    }
    return 0;
}
