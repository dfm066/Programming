#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,x,y;
    int chess[16][16];
    for(int i = 1; i <= 15; i++){
        for(int j = 1; j <= 15; j++){
            if(i%4==0||i%4==3||j%4==0||j%4==3)
                chess[i][j]=1;
            else
                chess[i][j]=2;
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&x,&y);
        if(chess[x][y]==1)
            printf("First\n");
        else
            printf("Second\n");
    }
    return 0;
}
