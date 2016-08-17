#define SIZE 100
#define MAX 200
#define TIMES 10
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void fetch(int *arr)
{
  int i;
  for(i=0;i<SIZE;i++)
  {
    arr[i]=rand()%MAX;
  }
}
void display(int *arr)
{
   int i;
   for(i=0;i<SIZE;i++)
     printf(" %d",*(arr+i));
}
int search(int *arr,int *tests)
{
  int i,j,sv,ss=0,t,tmp;
  for(i=0;i<TIMES;i++)
  {
    sv=rand()%MAX;
    t=0;
    printf("\n Search Value: %d\t",sv);
    for(j=0;j<SIZE;j++)
    {
        if(*(arr+j)==sv)
        {
	      printf("Found ! (Tests : %d)",t);
          ss++;
	      *(tests+i)=t;     // not *(tests+j)
	      if(j!=0)
	      {
	          tmp=*(arr+j);
	          *(arr+j)=*(arr+j-1);
	          *(arr+j-1)=tmp;
	      }

	      break;
        }
	else
        {
          t++;
	      if(j==SIZE-1)
          {

	       printf("Not Found");
	       *(tests+i)=t;
          }
        }
    }
  }
  return ss;
}
int avgt(int *tests)
{
  int i,avg=0;
  for(i=0;i<TIMES;i++)
  {
    avg+=*(tests+i);
  }
  return avg/TIMES;
}
int main()
{
  int *arr,*tests,ss,avg;
  srand(time(NULL));
  arr=(int *)malloc(sizeof(int)*SIZE);
  tests=(int *)malloc(sizeof(int)*TIMES);
  fetch(arr);
  display(arr);
  ss=search(arr,tests);
  avg=avgt(tests);
  printf("\n\n\n SEARCH STATS");
  printf("\n 1.Number of Searches Completed      : %d",TIMES);
  printf("\n 2.Number of Successful Searches     : %d",ss);
  printf("\n 3.Percentage of Successful Searches : %d",(ss*TIMES)/TIMES);
  printf("\n 4.Average Number of Tests per Search: %d",avg);
  free(arr);
  return 0;
}
