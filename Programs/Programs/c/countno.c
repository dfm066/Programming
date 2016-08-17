#include<stdio.h>
#include<stdlib.h>
long long ans=0;
void count_no()
{
    int cnt[2],*no1,*no2;

}
void print(int no)
{
    int i;
    for(i=0;i<no;i++)
    {
        printf("\n %d - %d",no-i,i);
    }
}
int main()
{
    int x;
    printf("\n Enter No : ");
    scanf("%d",&x);
    print(x);
    return 0;
}
