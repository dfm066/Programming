#include<stdio.h>
int ans=0;
void add(int x,int y)
{
    if(y==x-1)
        return;
    ans+=y;
    y--;
    add(x,y);
}
void main()
{
    int no1,no2;
    printf("\n Enter Range for series : ");
    scanf("%d%d",&no1,&no2);
    add(no1,no2);
    printf("\n Addition of %d to %d nos = %d",no1,no2,ans);
    return;
}
