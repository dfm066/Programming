#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;

void merge(int data[],int low,int mid,int high)
{
    int i=0,j=low,k=mid+1;
    int *tmp=(int*)malloc(sizeof(int)*(high-low+1));
    while(k<=high&&j<=mid)
    {
        if(data[j]<data[k])
        {
            tmp[i++]=data[j++];
        }
        else
        {
            tmp[i++]=data[k++];
        }
    }
    if(j>mid)
    {
        for(int h=k;h<=high;h++)
        {
            tmp[i++]=data[h];
        }
    }
    else
    {
        for(int h=j; h<=mid; h++)
        {
            tmp[i++]=data[h];
        }
    }
    for(i=low,k=0;i<=high;i++)
        data[i]=tmp[k++];
    free(tmp);
}
void mergeSort(int data[],int low,int high)
{
    int mid;
	#pragma omp parallel
    if(low<high)
    {
            mid=(low+high)/2;
            mergeSort(data,low,mid);
            mergeSort(data,mid+1,high);
            merge(data,low,mid,high);
    }
}
void display(int data[],int cnt)
{
    for(int i=0; i<cnt; i++)
        cout<<"\t"<<data[i];
}
int main()
{
    int data[1024];
    int cnt=0;
    cout<<"\nEnter count : ";
    cin>>cnt;
    cout<<"\nEnter "<<cnt<<" Nos : ";
    for(int i=0;i<cnt;i++)
    {
        cin>>data[i];
    }
    cout<<"\nData : ";
    display(data,cnt);
    mergeSort(data,0,cnt-1);
    cout<<"\nSorted Data : ";
    display(data,cnt);
}
