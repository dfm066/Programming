#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<array>
#include<cstdbool>

using namespace std;
vector<pair<int,int>> pw;
vector<int> x,y;
int m,fp,fw,n;

int Bound(int cp, int cw, int k){
    int b=cp;
    int c=cw;
    for(int i=k+1; i < n; i++){
        c += pw[i].second;
        if(c<m)
            b+=pw[i].first;
        else
            return b+(1-(c-m)/pw[i].second)*pw[i].first;
    }
    return b;
}

void BKnap(int k,int cp,int cw)
{

	if(cw+pw[k].second <= m)
	{
		y[k]=1;
		if(k<n-1)
            BKnap(k+1, cp+pw[k].first, cw+pw[k].second);
		if(cp+pw[k].first > fp && k == n-1){
            fp = cp+pw[k].first;
            fw = cw+pw[k].second;
            for(int j = 0 ; j < k; j++){
                x[j]=y[j];
            }
		}
	}
	if(Bound(cp,cw,k)>=fp){
       y[k]=0;
       if(k<n-1)
            BKnap(k+1,cp,cw);
       if(cp>fp && k == n-1){
            fp=cp;
            fw=cw;
            for(int j = 0 ; j < k; j++){
                x[j]=y[j];
            }
       }
	}
}

int main()
{
	int tmp1,tmp2,profit=0,weight=0;
	pair<int,int> tmp;
	printf("\nEnter Number of weights : ");
	scanf("%d",&n);
	printf("\nEnter Size of Knapsack : ");
	scanf("%d",&m);
	printf("\nEnter %d profit and weight : \n",n);
	for(int i = 0; i < n; i++)
	{
			scanf("%d%d",&tmp1,&tmp2);
			pw.push_back(make_pair(tmp1,tmp2));
            x.push_back(0);
            y.push_back(0);
	}
	sort(pw.begin(),pw.end(),[](pair<int,int> a, pair<int,int> b){
                return (float(b.first)/b.second)<(float(a.first)/a.second);
    });
    BKnap(0,0,0);
    printf("\nSolution Vector : \n");
    for(int i = 0 ; i < n; i++){
        if(x[i]==1){
             printf("%5d",pw[i].second);
            weight+=pw[i].second;
            profit+=pw[i].first;
        }
    }
    printf("\nProfit : %d\tWeight : %d ",profit,weight);
    return 0;

}
