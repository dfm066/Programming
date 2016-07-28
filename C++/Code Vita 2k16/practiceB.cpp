#include <cstdio>
#include <cmath>
int main(){
    int M,T,P;
    double r,R;
    scanf("%d %d %lf",&M,&T,&r);
    if(r==0)
        P = M*T;
    else{
        R = r /1200;
        P = M*(1-1/pow(1+R,T))/R;
    }
    printf("%d",P);
    return 0;
}
