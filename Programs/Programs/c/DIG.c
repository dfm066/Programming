#include<stdio.h>
#include<time.h>
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void main()
{
	int x,y,k,no=0,dig[10],i=0,count=0;
//	clrscr();
	printf("\n Enter No :");
	scanf("%d",&no);
//	clrscr();
	k=no;
	while(no>0)
	{
	  dig[i]=no%10;
	  no/=10;
	  i++;
	  count++;
	}
//	printf(" %d",count);
    if(k>0)
    {
	for(x=1;x<=5;x++)
	{
		for(i=count-1;i>=0;i--)
		{
			for(y=0;y<=6;y++)
			{
				switch(dig[i])
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
				}
			}
			if(dig[0]==6)
			{
				for(y=-2;y<=8;y++)
				{
					if(y!=0&&y!=-1&&y!=-2&&(((y==2||y==4||y==1)&&x==3)||y==3||x+y==8||(x==2&&y==4))&&y!=6&&y!=7&&y!=8)
					 printf("*");
					else
					 printf(" ");

				}
				for(y=0;y<=6;y++)
				{
					if(y!=0&&(x==y||x+y==6)&&y!=6)
					 printf("*");
					else
					 printf(" ");
				}
				for(y=0;y<=6;y++)
				{
					if(y!=0&&(x==1||x==3||y==1||y==5)&&y!=6)
					 printf("*");
					else
					 printf(" ");
				}
				for(y=0;y<=6;y++)
				{
					if(y!=0&&(((y==1||y==5)&&x<=3)||(x==4&&(y==2||y==4))||(x==5&&y==3))&&y!=6)
					 printf("*");
					else
					 printf(" ");
				}
				for(y=0;y<=6;y++)
				{
					if(y!=0&&(((x==1||x==5)&&(y>=2&&y<=4))||y==3)&&y!=6)
					 printf("*");
					else
					 printf(" ");
				}
			}
		}
			delay(50);
			printf("\n");
	}
    }
    else
	printf("\nXXXXXXXXXXXXXXXXXXX\n\n INVALID CHARACTER\n\nXXXXXXXXXXXXXXXXXXX");
	getch();
}
