/*
ID: itachi.1
LANG: C
TASK: milk2
*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *fin=fopen("milk2.in","r");
    FILE *fout=fopen("milk2.out","w");
    int t,cs,(*time)[2],no,cont=0,idle=0,st=0,en=0,tmp_ct,tmp_idl,flg=0;
    fscanf(fin,"%d",&t);
    time=(int(*)[])malloc(t*4);
    for(cs=0;cs<t;cs++)
    {
        fscanf(fin,"%d%d",(*(time+cs)+0),(*(time+cs)+1));
        if(flg==0)
        {
            st=*(*(time+cs)+0);
            en=*(*(time+cs)+1);
        }
        if(*(*(time+cs)+0)<=en)
        {
            en=*(*(time+cs)+1);
            flg=1;
        }
        else
        {
           flg=0;
           tmp_idl=*(*(time+cs)+0)-en;
            if(idle<tmp_idl)
                idle=tmp_idl;
        }
        tmp_ct=en-st;
        if(tmp_ct>cont)
            cont=tmp_ct;
        printf("\n %d %d",*(*(time+cs)+0),*(*(time+cs)+1));
    }
    fprintf(fout,"%d %d\n",cont,idle);
   fclose(fin);
    fclose(fout);
    exit(0);
}

