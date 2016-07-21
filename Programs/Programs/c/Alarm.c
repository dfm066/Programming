#include<stdio.h>
#include<windows.h>
void star(int,int,int,int,int,int);
void tone();
void sa(int);
void re(int);
void ga(int);
void ma(int);
void pa(int);
void dha(int);
void ni(int);
void sa_h(int);
int main()
{
    char ch;
    int i,j,m,s,h,k,temp[3];
    system("cls");
    printf("\n Set Alarm in HH:MM:SS : ");
    scanf("%d%c%d%c%d",&h,&ch,&m,&ch,&s);

    for(k=h;k>=0;k--)
    {
        if(k<h)
            m=59;
        for(i=m;i>=0;i--)
        {
            if(i<m)
                s=59;
            for(j=s;j>=0;j--)
            {
                system("cls");
                printf("\n====================================================================\n");
                star(k/10,k%10,i/10,i%10,j/10,j%10);
                printf("\n====================================================================\n");
                Beep(5131,25);
                Sleep(950);
                if(kbhit())
                    goto stop;
            }
            Beep(2163,25);
        }
    }
stop:if(k==0&&i==0&&j==0)
            {
                printf("\n Alarm");
                for(i=0;i<3;i++)
                 printf(": %d",temp[i]);
            }
         else
            printf("\n Alarm : %d:%d:%d",k,i,j);
    tone();
}
void tone()
{
     int i;
     sa(3);
     re(3);
     for(i=0;i<6;i++)
        ga(3);
     ga(6);
     ga(3);
     ga(3);
     re(3);
     ga(3);
     ma(3);
     ga(7);
     ga(3);
     ga(3);
     re(3);
     re(3);
     re(3);
//     ni(3);
//     re(3);
//     sa(3);

}
void sa(int t)
{
    Beep(130,t*100);
}
void re(int t)
{
    Beep(146,t*100);
}
void ga(int t)
{
    Beep(164,t*100);
}
void ma(int t)
{
    Beep(174,t*100);
}
void pa(int t)
{
    Beep(195,t*100);
}
void dha(int t)
{
    Beep(220,t*100);
}
void ni(int t)
{
    Beep(246,t*100);
}
void sa_h(int t)
{
    Beep(261,t*100);
}
void star(int h2,int h1,int m2,int m1,int s2,int s1)
{
    int x,y,i,d[8]={h2,h1,10,m2,m1,10,s2,s1};
    for(x=1;x<=5;x++)
    {
           for(i=0;i<=7;i++)
        {
                for(y=0;y<=6;y++)
                {
                    switch(d[i])
                    {
                        case 0:if(y!=6&&(x==1||x==5||y==1||y==5)&&y!=0)
                                    printf("*");
                                else
                                    printf(" ");
                                break;
                        case 1:if(y!=6&&((y==3&&x<=5)||(x==5&&(y>=2&&y<=4))||(x==2&&(y==2||y==3)))&&y!=0)
                                printf("*");
                               else
                                printf(" ");
                               break;
                        case 2:if(y!=6&&(x==1||x==3||x==5||(y==5&&x<=3)||(y==1&&x>3))&&y!=0)
                                printf("*");
                               else
                                printf(" ");
                               break;
                        case 3:if(y!=6&&(y==5||x==1||x==3||x==5)&&y!=0)
                                printf("*");
                               else
                                printf(" ");
                               break;
                        case 4:if(y!=6&&(x==3||(y==1&&x<=3)||y==5)&&y!=0)
                                printf("*");
                               else
                                printf(" ");
                               break;
                        case 5:if(y!=6&&(x==3||(y==1&&x<=3)||(y==5&&x>=3)||x==1||x==5)&&y!=0)
                                printf("*");
                               else
                                printf(" ");
                               break;
                        case 6:if(y!=6&&(x==1||y==1||x==5||x==3||(y==5&&x>=3))&&y!=0)
                                printf("*");
                               else
                                printf(" ");
                               break;
					case 7:if(y!=6&&(x==1||y==5)&&y!=0)
						printf("*");
					       else
						printf(" ");
					       break;
					case 8:if(y!=6&&(x==1||y==1||x==3||y==5||x==5)&&y!=0)
						printf("*");
					       else
						printf(" ");
					       break;
					case 9:if(y!=6&&(x==1||x==3||x==5||(y==1&&x<=3)||y==5)&&y!=0)
						printf("*");
					       else
						printf(" ");
						break;
                    case 10:if((y==4&&x==2)||(y==4&&x==4))
                                printf("*");
                            else
                                printf(" ");
				}

			}
			}
            printf("\n");
		}
}
