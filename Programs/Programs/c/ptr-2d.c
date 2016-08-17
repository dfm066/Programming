#include<stdio.h>
#include<conio.h>
void display(int*);
void main()
{
    int x[2][3]={{1,2,3},{4,5,6}};
    display(x);
    getch();
}
void display(int *p)
{
    int i,j;
    for(i=0;i<6;i++)
    {
        printf("%5d",*(p+i));
        if(i==2)
            printf("\n");
    }
}
