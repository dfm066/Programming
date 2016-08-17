#include<stdio.h>
#include<math.h>
int main()
{
    int i;
    for(i=1;i<30;i++)
        printf("\n%d : %lld",i,(long long)pow(2.0,i));
    return 0;
}
