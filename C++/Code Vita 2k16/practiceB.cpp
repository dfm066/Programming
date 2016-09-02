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
        P = M*(pow(1+R,T)-1)/(R*(pow(1+R,T)));
    }
    printf("%d",P);
    return 0;
}
