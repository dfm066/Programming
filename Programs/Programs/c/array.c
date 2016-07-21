#include<conio.h>
#include<stdio.h>
void main()
{
    int no[5],temp=0,i,j;
    printf("\n Enter 5 No: ");
    for(i=0;i<5;i++)
     scanf("%d",&no[i]);
   for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(no[i]>no[j])
            {
                temp=no[j];
                no[j]=no[i];
                no[i]=temp;
            }
        }
    }
    printf("\n Ascending Order :");
    for(i=0;i<5;i++)
    {
        printf(" %d ",no[i]);
    }
    getch();
}
