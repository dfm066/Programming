#include<stdio.h>
#include<conio.h>

void main()
{
    long int x[100][100],i,j,cnt,k,sum=0;
    system("cls");
    printf("\n Enter The Count : ");
    scanf("%ld",&cnt);
    for(i=0;i<cnt;i++)
    {
     //   for(k=0;k<cnt-i;k++)
     //       printf(" ");
        for(j=0;j<=i;j++)
        {
            if(i==j||j==0)
                x[i][j]=1;
            else
            {
                x[i][j]=x[i-1][j]+x[i-1][j-1];
            }
            printf("%ld ",x[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<cnt;i++)
    {
        sum+=x[cnt-1][i];
    }
    printf("\nsum = %ld",sum);
    getch();
    exit(0);
}

/*int prtpascal(int cnt,int pos)
{
    int i,j,x[100][100];
    for(i=0;i<=cnt;i++)
    {
        for(j=0;j<cnt;j++)
        {
            if(i+j>=cnt)
            {
                if(i+j==cnt||j==cnt-1)
                    x[i][j]=1;
                else
                    x[i][j]=x[i-1][j]+x[i-1][j+1];
                printf(" %d",x[i][j]);
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    return x[cnt][pos-1];
}
void main()
{
    int x[100][100],i,j,row,pos;
    system("cls");
    printf("\n Enter The Row And Position : ");
    scanf("%d%d",&row,&pos);
    if(row>=pos)
        printf("\n Element in %d row at %d position : %d",row,pos,prtpascal(row,pos));
    else
        printf("\n Invalid Input");
    exit(0);
}
*/
