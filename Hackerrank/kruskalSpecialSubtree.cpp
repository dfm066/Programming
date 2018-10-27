#include <bits/stdc++.h>
using namespace std;
int main(){
    map<int,vector<pair<int,int>>> graph;
    vector<int> parent;
    int N,M;
    int x,y,r;
    cin>>N>>M;
    for(int i =0 ; i <= N; i++){
        parent.push_back(0);
    }
    for(int i = 0; i < M; i++)
    {
        cin>>x>>y>>r;
        graph[r].push_back(make_pair(x,y));
    }
    int u,v,cnt=0;
    int cost = 0;
    for(auto i:graph){
        for(auto j:i.second){
            u = j.first;
            v= j.second;
            while(parent[u]){
                u = parent[u];
            }
            while(parent[v]){
                v = parent[v];
            }
            if(u!=v)
            {
                parent[v]=u;
            }
            else
                u=v=0;
            if(u||v){
                cost += i.first;
                cnt++;
                if(cnt==N-1){
                    cout<<cost<<endl;
                    return 0;
                }
            }
        }
    }
}
