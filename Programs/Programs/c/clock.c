#include<stdio.h>
#include<windows.h>
void star(int,int,int,int);
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
    int m1,m2,s1,s2,i,j,k,l,m,s;
    system("cls");
    printf("\n Set Timer For MM:SS : ");
    scanf("%d%c%d",&m,&ch,&s);
    m2=m/10;
    m1=m%10;
    s2=s/10;
    s1=s%10;
    for(i=m2;i>=0;i--)
    {
        if(i<m2)
           m1=9;
        for(j=m1;j>=0;j--)
        {
                if(j<m1)
                {
                    s2=5;
                    s1=9;
                }
                for(l=s2;l>=0;l--)
                {
                    if(l<s2)
                        s1=9;
                    for(k=s1;k>=0;k--)
                    {
                          system("cls");
                          printf("\n====================================\n");
                          star(i,j,l,k);
                          printf("\n====================================\n");
                          Beep(2261,50);
                          Sleep(940);
                          if(kbhit())
                             goto stop;
                    }
                }
        }
    }
   stop:
       printf("\n Alaram : %d%d:%d%d",i,j,l,k);
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
     ni(3);
     re(3);
     sa(3);

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

void star(int m2,int m1,int s2,int s1)
{
    int x,y,i,d[]={m2,m1,10,s2,s1};
    for(x=1;x<=5;x++)
    {
           for(i=0;i<=4;i++)
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
