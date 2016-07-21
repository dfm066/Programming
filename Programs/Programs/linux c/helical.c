#include<stdio.h>
int arr[10][10];
void fill_helical(int rw,int cl,int no,int ord)
{
	if(no==1)
	{
		arr[row][col]=no;
		return 1;	
	}
	else
	{
		if(cl+dir_cl<ord&&)
		{
			arr[rw][cl+dir_cl]=no--;
			if(fill_helical(rw+dir_rw,cl+(++dir_cl),no,ord))
				return 1;
			else
				no++;		
		}
		else if(rw+dir_rw<ord)
		{
				arr[rw+dir_rw][cl]=no--;
		}
	}
}
int main()
{
	int cl=0,rw=0,i,j,tmp,cnt,chk=0;
	printf("\n Enter order of matrix : ");
	scanf("%d",&cnt);
	fill_helical(0,0,9,cnt);
}
