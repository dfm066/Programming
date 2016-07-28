#include<cstdio>

int main(){
    int N,F,B,T,FD,BD;
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        if(i>0)
            printf("\n");
        scanf("%d %d %d %d %d",&F,&B,&T,&FD,&BD);
        if(F==B&&FD>F){
            printf("No Ditch");
        }
        else if(FD-F<=0){
            printf("%d F",FD*T);
        }
        else if(F>B){
            int cnt = 0;
            while(FD>(F-B)*cnt+F)
                cnt++;
            int corr = FD-(F-B)*cnt;
            printf("%d F",(F+B)*T*cnt+corr*T);
        }
        else{
            int cnt = BD/(B-F);
            int corr = -F;
            if(BD%(B-F)!=0)
             corr = (BD-(B-F)*cnt+F);
            printf("%d B",(F+B)*T*cnt+(F+corr)*T);
        }
    }
    return 0;
}
