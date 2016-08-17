#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,M,x,y,r,S;
    static int graph[3000][3000];
    cin>>N>>M;
    for(int i = 0; i < M; i++ ){
        cin>>x>>y>>r;
        if(graph[x-1][y-1]!=0&&graph[x-1][y-1]<r)
            continue;
        else
            graph[x-1][y-1] = r;
    }
    cin>>S;

    for(int i =0; i< N;i++){
        for(int j =0; j< N;j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
