#include<stdio.h>
#include<conio.h>
void main()
{
    int no,l=0,c=0,x,i,j,v=0;
 //   clrscr();
    printf("\n Enter the No: ");
    scanf("%d",&no);
    printf("\n Roman Conversion : ");
    if(no/50>0)
    {
        if(no/100>0)
        {
            l=no/100;
            no%=(l*100);

        }
        c=no/50;
        no%=50;
    }
//    printf(" %d %d",c,l);

    x=no/10;
    for(j=0;j<l;j++)
        printf("L");
    for(j=0;j<c;j++)
        printf("C");
    if(no%10>=5)
     {
          if(no%10==9)
            {
                i=0;
                v=0;
            }
          else
            {
                v=1;
                i=(no%10)-5;
            }
     }
     else
     {
        if(no%10==4)
         {
             v=1;
             i=1;
         }
         else
            i=no%10;
     }
    for(j=0;j<x;j++)
        printf("X");
    if(no%10!=4&&no%10!=9)
    {
        for(j=0;j<v;j++)
            printf("V");
        for(j=0;j<i;j++)
            printf("I");
    }
    else
        {
            if(no%10==9)
             printf("IX");
            else
            {
                for(j=0;j<i;j++)
                    printf("I");
                for(j=0;j<v;j++)
                    printf("V");
            }
        }
     getch();
}

