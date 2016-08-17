#include<stdio.h>
#include<string.h>


main()
{
  int i,j,length,k;
  char ch[10],ch1,manju;
  //clrscr();
  printf("enter a singal capital character :");
  gets(ch);
  length=strlen(ch);
  printf("\n %s",ch);
  printf("\n String Length : %d\n",length);
  for(i=1;i<=5;i++)
   {

       for(k=0;k<length;k++)
        {
            for(j=1;j<=7;j++)
            {
            switch(ch[k])
            {
            case 65:if(j!=1&&j!=7&&(i==1||i==3||j==2||j==6))
                      printf("*");
                    else
                      printf(" ");
                    break;
			case 66:if(j!=1&&j!=7&&((i==1&&j!=6)||(i==3&&j!=6)||(i==5&&j!=6)||j==2||(i==2&&j==6)||(i==4&&j==6)))
                       printf("*");
                    else
                      printf(" ");
                    break;
/*			else if(i==3)
			{
				if(j<=2||j>=8)
				printf(" ");
				else
				printf("*");
			}
			else if(i==4)
			{
				if(j==2||j==8)
				printf("*");
				else
				printf(" ");
			}
			else if(i==5)
			{
				if(j==1||j==9)
				printf("*");
				else
				printf(" ");

			}

		   }

     }
    else if(ch=='B')
     {
		for(j=1;j<=5;j++)
		{
			if(i==1||i==5)
			{
				if(j<5)
				printf("*");
				else
				printf(" ");
			}
			else if(i==2||i==4)
			{
				if(j==1||j==5)
				printf("*");
				else
				printf(" ");
			}
			else if(i==3)
			{
				if(j==4)
				printf(" ");
				else
				printf("*");
			}

		}

     }
     if(ch=='C')
     {
		for(j=1;j<=4;j++)
		{
			if(i==1||i==5)
			{
				if(j>0)
				printf("*");
			}
			else if(i==2||i==3||i==4)
			{
				if(j==1)
				printf("*");
				else
				printf(" ");
			}

		}


     }
     else if(ch=='D')
     {
		for(j=1;j<=5;j++)
		{
			if(i==1||i==5)
			{
				if(j<5)
				printf("*");
				else
				printf(" ");

			}
			else if(i==2||i==3||i==4)
			{
				if(j==1||j==5)
				printf("*");
				else
				printf(" ");
			}
		}
     }
     else if(ch=='E')
     {
		for(j=1;j<=4;j++)
		{
			if(i==1||i==3||i==5)
			{
				if(j>=1)
				printf("*");
			}
			else if(i==2||i==4)
			{
				if(j>=2)
				printf(" ");
				else
				printf("*");
			}

		}

     }
     else if(ch=='F')
     {
		for(j=1;j<=4;j++)
		{
			if(i==1||i==3)
			{
				if(j>0)
				printf("*");

			}
			else if(i!=1||i!=3)
			{
				if(j==1)
				printf("*");
				else
				printf(" ");
			}

		}

     }
     else if(ch=='G')
     {
		for(j=1;j<=5;j++)
		{
			if(i==1||i==5)
			{
				if(j==2||j==3||j==4)
				printf("*");
				else
				printf(" ");
			}
			else if(i==2)
			{
				if(j==1)
				printf("*");
				else
				printf(" ");
			}
			else if(i==3)
			{
				if(j==2)
				printf(" ");
				else
				printf("*");
			}
			else if(i==4)
			{
				if(j==1||j==4)
				printf("*");
				else
				printf(" ");
			}

		}
    }
    else if(ch=='H')
    {
		for(j=1;j<=5;j++)
		{
			if(i==3)
			{
				if(j>0)
				printf("*");
			}
			else if(i!=3)
			{
				if(j>=2&&j<=4)
				printf(" ");
				else
				printf("*");
			}
		}

    }
    else if(ch=='I')
    {
		for(j=1;j<=5;j++)
		{
			if(i==1||i==5)
			{
				if(j>0)
				printf("*");

			}
			else if(i>=2&&i<=4)
			{
				if(j==3)
				printf("*");
				else
				printf(" ");
			}
		}

    }
    else if(ch=='J')
    {
		for(j=1;j<=4;j++)
		{
			if(i==1)
			{
				if(j!=1)
				printf("*");
				else
				printf(" ");
			}
			else if(i==2||i==3)
			{
				if(j==3)
				printf("*");
				else
				printf(" ");
			}
			else if(i==4)
			{
				if(j==1||j==3)
				printf("*");
				else
				printf(" ");
			}
			else if(i==5)
			{
				if(j==4)
				printf(" ");
				else
				printf("*");
			}
		}

    }
    else if(ch=='K')
    {
		for(j=1;j<=4;j++)
		{
			if(i==1||i==5)
			{
				if(j==1||j==4)
				printf("*");
				else
				printf(" ");
			}
			else if(i==2||i==4)
			{
				if(j==1||j==3)
				printf("*");
				else
				printf(" ");
			}
			else if(i==3)
			{
				if(j==1||j==2)
				printf("*");
				else
				printf(" ");
			}
		}
    }
    else if(ch=='L')
    {
		for(j=1;j<=5;j++)
		{
			if(i<5)
			{
				if(j==1)
				printf("*");
				else
				printf(" ");
			}
			else if(i==5)
			{
				if(j>0)
				printf("*");

			}

		}

    }
    else if(ch=='M')
    {
		printf("*");
		for(j=1;j<=7;j++)
		{
			if(i==1)
			{
				if(j>=1)
				printf(" ");
				}
			else if(i==2)
			{
				if(j==1||j==7)
				printf("*");
				else
				printf(" ");
			}
			else if(i==3)
			{
				if(j==2||j==6)
				printf("*");
				else
				printf(" ");
			}
			else if(i==4)
			{
				if(j==3||j==5)
				printf("*");
				else
				printf(" ");
			}
			else if(i==5)
			{
				if(j==4)
				printf("*");
				else
				printf(" ");
			}
		}
				printf("*");
    }
    else if(ch=='N')
    {
		printf("*");
		for(j=1;j<=3;j++)
		{
			if(i==1)
			{
				if(j>0)
				printf(" ");
			}
			else if(i==2)
			{
				if(j==1)
				printf("*");
				else
				printf(" ");
			}
			else if(i==3)
			{
				if(j==2)
				printf("*");
				else
				printf(" ");
			}
			else if(i==4)
			{
				if(j==3)
				printf("*");
				else
				printf(" ");
			}
			else if(i==5)
			{
				if(j>0)
				printf(" ");
			}
		}
			printf("*");
    }
    else if(ch=='O')
    {
		for(j=1;j<=5;j++)
		{
			if(i==1||i==5)
			{
				if(j!=1&&j!=5)
				printf("*");
				else
				printf(" ");
			}
			else if(i>=2&&i<=4)
			{
				if(j>=2&&j<=4)
				printf(" ");
				else
				printf("*");
			}
		}
    }
    else if(ch=='P')
    {
		for(j=1;j<=4;j++)
		{
			if(i==1||i==3)
			{
				if(j<4)
				printf("*");
			}
			else if(i>3)
			{
				if(j==1)
				printf("*");
				else
				printf(" ");
			}
			else if(i==2)
			{
				if(j==1||j==4)
				printf("*");
				else
				printf(" ");
			}
		}

    }
    else if(ch=='Q')
    {
		for(j=1;j<=6;j++)
		{
			if(i==1||i==4)
			{
				if(j==2||j==4)
				printf("*");
				else
				printf(" ");
			}
			else if(i==2)
			{
				if(j==1||j==5)
				printf("*");
				else
				printf(" ");
			}
			else if(i==3)
			{
				if(j==1||j==3||j==5)
				printf("*");
				else
				printf(" ");
			}
			else if(i==5)
			{
				if(j==5)
				printf("*");
				else
				printf(" ");
			}
		}
    }
    else if(ch=='R')
    {
		for(j=1;j<=4;j++)
		{
			if(i==1||i==3)
			{
				if(j<4)
				printf("*");
				else
				printf(" ");

			}
			else if(i==2)
			{
				if(j==1||j==4)
				printf("*");
				else
				printf(" ");
			}
			else if(i==4)
			{
				if(j==1||j==3)
				printf("*");
				else
				printf(" ");
			}
			else if(i==5)
			{
				if(j==1||j==4)
				printf("*");
				else
				printf(" ");
			}
		}
    }
    else if(ch=='S')
    {
		for(j=1;j<=4;j++)
		{
			if(i==1||i==5)
			{
				if(j==2||j==3)
				printf("*");
				else
				printf(" ");
			}
			else if(i==2)
			{
				if(j==1||j==4)
				printf("*");
				else
				printf(" ");
			}
			else if(i==3)
			{
				if(j==2)
				printf("*");
				else
				printf(" ");
			}
			else if(i==4)
			{
				if(j==1||j==4)
				printf("*");
				else
				printf(" ");
			}
		}

    }
   else if(ch=='T')
   {
		for(j=1;j<=5;j++)
		{
			if(i==1)
			{
				if(j>=1)
				printf("*");
			}
			else if(i>=2)
			{
				if(j==3)
				printf("*");
				else
				printf(" ");
			}
		}
   }
   else if(ch=='U')
   {

		for(j=1;j<=5;j++)
		{
			if(i<5)
			{
				if(j!=1&&j!=5)
				printf(" ");
				else
				printf("*");
			}
			else if(i==5)
			{
				if(j!=1&&j!=5)
				printf("*");
				else
				printf(" ");
			}
		}

   }
   else if(ch=='V')
   {
		for(j=1;j<=9;j++)
		{
			if(i==1)
			{
				if(j!=1&&j!=9)
				printf(" ");
				else
				printf("*");
			}
			else if(i==2)
			{
				if(j==2||j==8)
				printf("*");
				else
				printf(" ");
			}
			else if(i==3)
			{
				if(j==3||j==7)
				printf("*");
				else
				printf(" ");
			}
			else if(i==4)
			{
				if(j==4||j==6)
				printf("*");
				else
				printf(" ");
			}
			else if(i==5)
			{
				if(j==5)
				printf("*");
				else
				printf(" ");
			}
		}

   }
   else if(ch=='W')
   {
		for(j=1;j<=17;j++)
		{
			if(i==1)
			{
				if(j==1||j==9||j==17)
				printf("*");
				else
				printf(" ");
			}
			else if(i==2)
			{
				if(j==2||j==8||j==10||j==16)
				printf("*");
				else
				printf(" ");
			}
			else if(i==3)
			{
				if(j==3||j==7||j==11||j==15)
				printf("*");
				else
				printf(" ");
			}
			else if(i==4)
			{
				if(j==4||j==6||j==12||j==14)
				printf("*");
				else
				printf(" ");
			}
			else if(i==5)
			{
				if(j==5||j==13)
				printf("*");
				else
				printf(" ");
			}
		}
   }
   else if(ch=='X')
   {
		for(j=1;j<=5;j++)
		{
			if(i==1||i==5)
			{
				if(j==1||j==5)
				printf("*");
				else
				printf(" ");
			}
			else if(i==2||i==4)
			{
				if(j==2||j==4)
				printf("*");
				else
				printf(" ");
			}
			else if(i==3)
			{
				if(j==3)
				printf("*");
				else
				printf(" ");
			}
		}
   }
   else if(ch=='Y')
   {
		for(j=1;j<=5;j++)
		{
			if(i==1)
			{
				if(j==1||j==5)
				printf("*");
				else
				printf(" ");
			}
			else if(i==2)
			{
				if(j==2||j==4)
				printf("*");
				else
				printf(" ");
			}
			else if(i>=3)
			{
				if(j==3)
				printf("*");
				else
				printf(" ");
			}
		}
   }
   else if(ch=='Z')
   {
		for(j=1;j<=5;j++)
		{
			if(i==1||i==5)
			{
				if(j>0)
				printf("*");
				else
				printf(" ");
			}
			else if(i==2)
			{
				if(j==4)
				printf("*");
				else
				printf(" ");
			}
			else if(i==3)
			{
				if(j==3)
				printf("*");
				else
				printf(" ");
			}
			else if(i==4)
			{
				if(j==2)
				printf("*");
				else
				printf(" ");
			}*/
		}

            }

        }
         printf("\n");
  }

//printf("_____________________________");
//}
//getch();
return (0);
}
