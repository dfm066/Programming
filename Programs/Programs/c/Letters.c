#include<stdio.h>
void main()
{
    int i,j,letters;
    char name[10];
    printf("\n Enter Your Name :");
    gets(name);
    printf("====================================================================\n");
    for(i=1;i<=5;i++)
    {
        for(letters=0;letters<strlen(name);letters++)
        {
            for(j=0;j<=5;j++)
            {
                if(name[letters]>=97)
                   name[letters]-=32;
                switch(name[letters])
                {
                    case 65:if(j!=0&&(i==1||i==3||j==1||j==5))
                                printf("*");
                            else
                                printf(" ");
                            break;
                    case 66:if(j!=0&&(j==1||(j==5&&(i==2||i==4)||((i==1||i==3||i==5)&&j!=5))))
                                printf("*");
                            else
                                printf(" ");
                            break;
                }
            }
        }
        printf("\n");
    }
    printf("====================================================================");
}
