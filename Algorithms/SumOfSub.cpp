#include<cstdio>
#include<vector>
#include<algorithm>

std::vector<int> w,x;
int m;
void SumOfSub(int s,int k,int r)
{
	x[k]=1;
	if(s+w[k]==m)
	{
		for(int i = 0;i < k; i++)
		{
			if(x[i]==0)
				continue;
			printf("%3d,",w[i]);
		}
		printf("%3d.",w[k]);
		printf("\n");
		return;
	}
	else if(s+w[k]+w[k+1]<=m)
		SumOfSub(s+w[k],k+1,r-w[k]);
	if(s + r - w[k] >= m && s + w[k+1] <= m)
	{
		x[k]=0;
		SumOfSub(s,k+1,r-w[k]);
	}
	return;
}

int main()
{
	int cnt,sum=0,tmp;
	printf("\nEnter Array size : ");
	scanf("%d",&cnt);
	printf("\nEnter %d elements : ",cnt);
	for(int i = 0; i < cnt; i++)
	{
			scanf("%d",&tmp);
			sum+=tmp;
			w.push_back(tmp);
			x.push_back(0);
	}
	std::sort(w.begin(),w.end());
	for(int i = 0; i < cnt; i++)
	{
			printf("%5d",w[i]);
	}

	printf("\n Enter Sum of Subset : ");
	scanf("%d",&m);
	printf("\nAll Subsets with Sum %d : \n",m);
	SumOfSub(0,0,sum);

}
