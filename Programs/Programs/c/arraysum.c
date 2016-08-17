#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[5],sum=0,i,max=0,min=0,tmp[2];
//    p=&a;
    printf("\n Enter 5 No : ");
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];

        if(a[i]>max)
            max=a[i];

    }
    printf("\n Array is  : ");
    min=a[0];
    for(i=0;i<5;i++)
    {
        printf("%5d",a[i]);
        if(a[i]<min)
            min=a[i];

    }
    //print(p);
    printf("\n Sum of all elements  : %d\n MIN = %d\n Max = %d",sum,min,max);
    return 0;
}
