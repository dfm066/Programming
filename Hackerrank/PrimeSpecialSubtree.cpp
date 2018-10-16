#include <bits/stdc++.h>
#define INF 100001
using namespace std;

int graph[3001][3001];
int flg[3001];
int main()
{
    int N , M;
    int x, y, r;
    int curr_des,curr_min,curr_src;
    int curr = 0;
    int cost = 0;
    vector<int> visited;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            graph[i][j]=INF;
        }
    }

    for(int i = 0; i < M; i++){
        cin >> x >> y >> r;
        graph[x][y]=r;
        graph[y][x]=r;
    }
    cin >> curr;
    flg[curr] = 1;
    visited.push_back(curr);
    while(visited.size()!=N){
        curr_min = INF+1;
        for(auto i:visited){
            for(int j = 1; j <= N; j++){
                if(flg[j]!=1){
                    if(curr_min>graph[i][j])
                    {
                        curr_src = i;
                        curr_des = j;
                        curr_min = graph[i][j];
                    }
                }
            }
        }
        flg[curr_des] = 1;
        cost += curr_min;
        graph[curr_src][curr_des]= INF;
        graph[curr_des][curr_src]= INF;
        visited.push_back(curr_des);
    }
    cout<<cost<<endl;
    return 0;
}
