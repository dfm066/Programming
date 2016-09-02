#include<cstdio>
#include<cmath>

int main(){

        double t,d,x,y,va,vb;
        scanf("%lf %lf %lf %lf",&x,&y,&va,&vb);
        if(x<0||y<0||va<0||vb<0){
            printf("Invalid Input");
            return 0;
        }
        t  = (x*va+y*vb)/(va*va+vb*vb);
        d = sqrt((x-t*va)*(x-t*va)+(y-t*vb)*(y-t*vb));
        if(d==0)
            printf("%0.1lf @ %lf",d,t);
        else
            printf("%0.11lf @ %lf",d,t);
        return 0;
}
