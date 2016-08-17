#include<stdio.h>
#include<stdlib.h>
int main()
{
    long int t,*no,tmp,cnt,cs,chk,i,tmp_chk,ans;
    scanf("%ld",&t);
    no=(long int*)malloc(t*sizeof(long int));
    for(cs=0;cs<t;cs++)
    {
        scanf("%ld",no+cs);
        ans=*(no+cs)/5;
        cnt=0;
        chk=5;
        for(i=0;i<ans;i++)
        {
            tmp_chk=chk;
            while(tmp_chk/5>0&&tmp_chk%5==0)
            {
                cnt++;
                tmp_chk/=5;
            }
            chk+=5;
        }
        ans=cnt;
        *(no+cs)=ans;
    }
    for(cs=0;cs<t;cs++)
    {
        printf("%ld\n",*(no+cs));
    }
    return 0;
}
