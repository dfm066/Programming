/*
ID: itachi.1
LANG: C
TASK: beads
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    FILE *fin=fopen("beads.in","r");
    FILE *fout=fopen("beads.out","w");
    int i,cnt,tmp,chk=0,st,en,j,r,f,t_cnt;
    char ch1,ch2,t_ch,*str;
    fscanf(fin,"%d",&cnt);
    str=(char*)malloc(cnt);
    for(i=0;;i++)
    {
        *(str+i)=fgetc(fin);
        if(*(str+i)==EOF)
        {
            *(str+i)='\0';
            break;
        }
        else if(*(str+i)=='\n')
        {
            i--;
        }
    }
    for(i=0;i<cnt;i++)
    {
        if(i-1<0)
            r=cnt-1;
        else
            r=i-1;
        if(i+1==cnt)
            f=0;
        else
            f=i+1;
        st=1;
        en=0;
        ch1=*(str+i);
        ch2=*(str+r);
        t_cnt=0;
        for(j=f;;j++)
        {
            if(j==cnt)
                j=0;
            if(t_cnt==cnt)
                break;
            t_ch=*(str+j);
            if(*(str+j)==ch1||*(str+j)=='w'||(ch1=='w'&&t_ch!='w'))
            {
                if(ch1=='w')
                    ch1=t_ch;
                st++;
            }
            else
            {
                     break;
            }

            if(st==cnt)
            {
                fprintf(fout,"%d\n",st);
                exit(0);
            }
              t_cnt++;
        }
        t_cnt=0;
        for(j=r;;j--)
        {
            if(t_cnt==cnt)
                break;
            t_ch=*(str+j);

            if(*(str+j)==ch2||*(str+j)=='w'||(ch2=='w'&&t_ch!='w'))
            {
                if(ch2=='w')
                    ch2=t_ch;
                en++;
            }
            else
            {
                  break;
            }
            if(j==0)
                j=cnt;
            t_cnt++;
         }
        tmp=st+en;
        chk=(tmp>chk)?tmp:chk;
        if(chk>cnt)
            chk=cnt;
    }
    fprintf(fout,"%d\n",chk);
    exit(0);
}

