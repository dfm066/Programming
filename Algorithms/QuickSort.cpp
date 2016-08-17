#include<iostream>
#include<cstdio>
#include<omp.h>
using namespace std;

#define INF 999
void swap(int *data,int i,int j){
    int tmp=data[i];
    data[i]=data[j];
    data[j]=tmp;
}
int partition(int *data,int st,int en)
{
    int pivot=data[st];
    int i=st,j=en;
    while(1){
        for(;data[i]<pivot;i++);
        for(;data[j]>pivot;j--);
        if(i<j) swap(data,i,j);
        else return j;
    }
}
void QuickSort(int *data,int st,int en)
{
    int pivot;
#pragma omp parallel
    {
        int tid=omp_get_thread_num();
        if(tid==0)
            printf("\nNo of threads : %d",omp_get_max_threads());
        if(st<en)
        {
            pivot=partition(data,st,en);
            QuickSort(data,st,pivot-1);
            QuickSort(data,pivot+1,en);
        }
    }
}
int main()
{
        int data[]={123,4531,214,534,68};
        int cnt=5;

//      cout<<"\nEnter Data count : ";
//      cin>>cnt;
//      data=new int[cnt+1];
//      cout<<"\nEnter "<<cnt<<" data elements : "<<endl;
//      for(int i=0; i<cnt; i++){
//           cin>>data[i];
//      }
//      data[cnt]=INF;

        omp_set_num_threads(4);
        QuickSort(data,0,cnt-1);
        cout<<"\nData elements : "<<endl;
        for(int i=0; i<cnt; i++){
            cout<<data[i]<<"\t";
        }
        return 0;
}
