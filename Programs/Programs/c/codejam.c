#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
FILE *fp,*out;
int cnt,no1[4],no2[4],i,j,t,t1,t2,tmp,cs;
void check()
{
    FILE *out;
    int i,cnt=0,j,ans;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(no1[i]==no2[j])
            {
                ans=no1[i];
                cnt++;
                break;
            }
        }
    }
    if(cnt==0)
        fprintf(out,"Case #%d: Volunteer cheated!\n",cs);
    else if(cnt==1)
        fprintf(out,"Case #%d: %d\n",cs,ans);
    else
        fprintf(out,"Case #%d: Bad magician!\n",cs);
}
void main()
{
    fp=fopen("small.in","r");
    out=fopen("xyz.out","w");
    fscanf(fp,"%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        fscanf(fp,"%d",&t1);
        for(j=1;j<=4*(t1-1);j++)
            fscanf(fp,"%d",&tmp);
        for(j=1;j<=4;j++)
            fscanf(fp,"%d",&no1[j-1]);
        for(j=1;j<=4*(4-t1);j++)
            fscanf(fp,"%d",&tmp);
        fscanf(fp,"%d",&t2);
        for(j=1;j<=4*(t2-1);j++)
            fscanf(fp,"%d",&tmp);
        for(j=1;j<=4;j++)
            fscanf(fp,"%d",&no2[j-1]);
        for(j=1;j<=4*(4-t2);j++)
            fscanf(fp,"%d",&tmp);
        check();
    }
    return 1;
}
