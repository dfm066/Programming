#include<cstdio>
#include<cstdbool>
int** graph=0;
int* x;
int node,m,cnt;
void NextValue(int index){
    int i;
    while(true){
        x[index] = (x[index]+1)%(m+1);
        if(x[index]==0) return;
        for(i = 0; i < node; i++){
            if(graph[index][i]!=0&&x[index]==x[i])
                break;
        }
        if(i == node) return;
    }
}

void mColoring(int index){

    while(true){
        NextValue(index);
        if(x[index]==0) return;
        if(index==node-1){
            printf("\nColors for vertices : \n");
            for(int i = 0; i < node; i++){
                printf("%5d",x[i]);
            }
            cnt++;
        }
        else mColoring(index+1);
    }
}

int main(){

    printf("\nEnter Node count : ");
    scanf("%d",&node);
    printf("\nEnter the Value of M : ");
    scanf("%d",&m);
    graph=new int*[node];
    x=new int[node];
    for(int i = 0; i < node; i++){
        graph[i]=new int[node];
        x[i]=0;
    }
    printf("\nEnter Adjacency matrix for graph : \n");
    for(int i = 0; i < node; i++){
        for(int j = 0; j < node; j++){
            scanf("%d",&graph[i][j]);
        }
    }
    mColoring(0);
    printf("\nPossible Ways to Color : %d\n",cnt);
    return 0;

}
