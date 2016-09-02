#include<cstdio>

int main(){
    int N,A,sum=0;
    scanf("%d",&N);
    for(int i =0; i< N; i++){
        scanf("%d",&A);
        sum ^= A;
    }
    if(sum!=0)
        printf("AMAN");
    else
        printf("JASBIR");
    return 0;
}
