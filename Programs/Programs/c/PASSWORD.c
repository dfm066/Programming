#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
main()
{
	int cnt,i,j,flg=1,flg_1=1,flg_2=1,flg_3=1;;
	char pass[20]={0};
	system("cls");
	printf("\n Enter Password : ");
	for(i=0;i<20;i++)
    {
        pass[i]=getch();
        if(pass[i]==13)
            break;
        if(pass[i]==8)
        {
            pass[i]='\0';
            pass[i-1]='\0';
            i=i-2;
            printf("\b \b");
        }
        else
            printf("*");

    }
	cnt=strlen(pass)-1;
	if(cnt>=8)
    {
		if(pass[0]>='A'&&pass[0]<='Z')
		  flg++;
        else
		  printf("\n First Letter is not Capital\n");
			for(i=1;i<cnt;i++)
			{
				if(pass[i]>='a'&&pass[i]<='z')
				{
					flg_1++;
				//	goto N;
				}
				else
				{
                        if(pass[i]>='0'&&pass[i]<='9')
                        {
                            flg_2++;
                   //         goto N;
                        }
                        else
                        {
                            flg_3++;
                 //           goto N;
                        }
				}
			   // N: ;
			}
        if(flg_1==1)
            printf("\n No Lower Case character\n");
        if(flg_2==1)
            printf("\n No Digit character\n");
        if(flg_3==1)
            printf("\n No Special Symbol\n");
	}
	else
		printf("\n Password length must be greater than 8\n");
	if(flg_1>1&&flg_2>1&&flg_3>1&&flg>1)
        printf("\n\n Password is Valid");
	else
        printf("\n Password is invalid");
	printf("\n Your Password Is : %s",pass);
	getch();
}
