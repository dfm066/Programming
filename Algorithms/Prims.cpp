#include<cstdio>
#include<utility>

#define MP make_pair

using namespace std;

void findMin(int **cost,int n,int &k,int &l){
    int m=cost[0][0];
    for(int i = 0; i < n; i++ ){
        for(int j = 0; j < n; j++){
            if(m>cost[i][j]){
                k=i;
                l=j;
                m=cost[i][j]
            }
        }
    }
    return;
}
int main(){
    int** cost,t;
    int n,i;
    printf("\n Enter No of vertices : ");
    scanf("%d",&n);
    cost = new int*[n];
    t = new int[n][2];
    for(i = 0; i < n; i++){
        cost[i] = new int [n];
    }
    printf("\nEnter Cost Adjacency Matrix : \n");
    for(i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&cost[i][j]);
        }
    }
}
