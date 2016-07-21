# include <stdio.h>

/* Function to swap values at two pointers */
void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(int *a, int i, int n)
{
   int j,k;
   if (i == n)
    {
        for(k=0;k<=n;k++)
            printf("%d ", *(a+k));
        printf("\n");
    }
   else
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
}
int main()
{
   int *a,no,i;
   printf("\n Enter Range  : ");
   scanf("%d",&no);
   a=(int*)malloc(2*no);
   for(i=1;i<=no;i++)
        *(a+i-1)=i;
   permute(a, 0, no-1);
   free(a);
   return 0;
}

