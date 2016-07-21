#include<cstdio>
#include<cstdbool>
#include<cmath>
int* x;
int cnt;

bool Place(int k, int i){
        for(int j = 1; j <= k-1; j++){
            if(x[j]==i||std::abs(x[j]-i)==std::abs(j-k))
                return false;
        }
        return true;
}

void NQueens(int k,int n){
    for(int i = 1; i <= n; i++){
        if(Place(k,i)){
            x[k]=i;
            if(k==n){
                printf("\n%d possible way : \n\n",++cnt);
                for(int j = 1; j <= n; j++){
                    for(int k = 1; k <= n; k++){
                        if(x[j]==k)
                            printf("Q  ");
                        else
                            printf("-  ");
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else
                NQueens(k+1,n);
        }
    }
}

int main(){
        int n;
        printf("\nEnter No of Queens : ");
        scanf("%d",&n);
        x = new int[n+1];
        NQueens(1,n);
        return 0;
}
