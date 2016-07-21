#include<bhingary.h>
void main()
{
    int x,y,i,j;
     for(i=0;i<=20;i++)
    {
        for(j=0;j<=30;j++)
        {
            if(i==0&&j==1)
               printf("#");
            else if(i==0&&j==30)            {
                printf("#");            }
            else if(i==20&&j==1)
                printf("#");
            else if(i==20&&j==30)
                printf("#");
            else if(j!=0&&(i==0||i==20))
                printf("=");
            else if(j==1||j==30)
                printf("|");
            else
                printf(" ");
        }
        printf("\n");
    }
    for(y=0;y<5;y++)
    {
        for(x=0;x<28;x++)
        {
            gotoxy(x+2,y+8);
            if(x+y>1&&y-x<=2&&x-y<26&&x+y<30)
                printf("$");
            else
                printf(" ");
        }
    }
    getch();
}
