#include<conio.h>
#include<stdio.h>
void main()
{
    int i,j,n,k,m1[5][5],m2[5][5],m3[5][5]={0};
    printf("\n Enter The order of the matrix :");
    scanf("%d",&n);
    printf("\n Enter the elements of first Matrix :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&m1[i][j]);
        }
    }
    printf("\n Enter the lements of the second Matrix :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&m2[i][j]);
        }
    }
    for(k=0;k<n;k++)
    {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(i==j)
                       m3[k][i]+=m1[k][j]*m2[j][k];
                    else
                       m3[k][i]+=m1[k][j]*m2[j][i];
                }
            }
    }
    printf("\n Matrix Multiplication :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%3d",m3[i][j]);
        }
        printf("\n");
    }
    getch();
}
