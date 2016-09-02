#include<cstdio>
#include<cstdbool>

int** graph=0;
int* x;
int n,cnt;

void NextValue(int index){
    int i;
    while(true){
        x[index] = (x[index]+1)%(n+1);
        if(x[index]==0) return;
        if(graph[x[index-1]][x[index]]!=0){
            for(i = 1; i <= index-1; i++){
                if(x[i]==x[index]) break;
            }
            if(i == index)
                if(index<n||(index==n&&graph[x[n]][x[1]]!=0))
                    return;
        }
    }
}

void Hamiltonian(int k){

    while(true){
        NextValue(k);
        if(x[k]==0) return;
        if(k==n){
            printf("\nSolution : \n");
            for(int i = 1; i <= n; i++){
                printf("%5d",x[i]);
            }
        }
        else Hamiltonian(k+1);
    }
}

int main(){

    printf("\nEnter Node count : ");
    scanf("%d",&n);
    graph=new int*[n+1];
    x=new int[n+1];
    for(int i = 1; i <= n; i++){
        graph[i]=new int[n+1];
        x[i]=0;
    }
    x[1]=1;
    printf("\nEnter Adjacency matrix for graph : \n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d",&graph[i][j]);
        }
    }
    Hamiltonian(2);
    return 0;

}
