#include<iostream>
#include<stdlib.h>
using namespace std;

void sort(int *din,int *num,int n)
{
    int tmpN,tmpD;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n ;j++)
        {
            if((float)num[i]/din[i]<(float)num[j]/din[j])
            {
                tmpN=num[i];
                tmpD=din[i];
                num[i]=num[j];
                din[i]=din[j];
                num[j]=tmpN;
                din[j]=tmpD;
            }
        }
}
float GreedyKnapsack(int *value,int *data,int size,int n)
{
    int lim=size,i;
    float ans=0.0;
    float *sol;
    sol=(float*)malloc(sizeof(float)*n);
    for(i=0; i<n;i++)
            sol[i]=0.0;
    for(i=0; i<n; i++)
    {
        if(data[i]>lim)
            break;
        sol[i]=1.0;
        lim=lim-data[i];
    }
    if(i<=n)
        sol[i]=(float)lim/data[i];
   cout<<endl;
    for( i = 0; i < n; i++)
    {
            ans = ans + sol[i]*value[i];
        cout<<sol[i]<<"\t"<<value[i]<<"\t"<<data[i]<<endl;
    }
    return ans;
}
int main()
{
    int *profit,*weight;
    int ksize,n,ans;
    cout<<"\nEnter value of n : ";
    cin>>n;
    cout<<"\nEnter size of knapsack : ";
    cin>>ksize;
    profit=(int*)malloc(sizeof(int)*n);
    weight=(int*)malloc(sizeof(int)*n);
    cout<<"\nEnter profits : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>profit[i];
    }
    cout<<"\nEnter weights : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>weight[i];
    }
    sort(weight,profit,n);
    cout<<"Solution for knapsack is : "<<GreedyKnapsack(profit,weight,ksize,n);
    return 0;
}
