#include<iostream>
#include<vector>
using namespace std;

void BubbleSort(int *data,int n)
{
    bool swapped;
    int newn;
    do
    {
        newn = 0;
        for(int i = 0; i < n-1; i++){
            if(data[i]>data[i+1]){
                swap(data[i],data[i+1]);
                swapped = true;
                newn=i+1;
            }
        }
        n=newn;
    }while(n!=0);
}

int main(){
    int* data;
    int cnt,i,tmp;
    cout<<"\nEnter No of Elements : ";
    cin>>cnt;
    data = new int[cnt];
    cout<<"\nEnter Nos : \n";
    for(i = 0; i < cnt; i++){
        cin>>data[i];
    }
    BubbleSort(data,cnt);
    cout<<"\nElements are : ";

    for(i = 0; i < cnt; i++){
        cout<<data[i]<<"\t";
    }
    return 0;
}
