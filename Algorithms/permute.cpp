#include<iostream>
#include<conio.h>
using namespace std;
void swap(int data[],int i,int j);
void perm(int data[],int curr,int sz){
    if(curr==sz-1){
            cout<<endl;
        for(int j=0;j<sz;j++){
            cout<<" "<<data[j];
        }
    }
    else{
        for(int i=curr;i<sz;i++){
            swap(data,curr,i);
            perm(data,curr+1,sz);
            swap(data,curr,i);
        }
    }
}
int main(){
    int data[1024];
    int cnt;
    cout<<"\nEnter data size : ";
    cin>>cnt;
    cout<<"\nEnter "<<cnt<<" data element : ";
    for(int i=0;i<cnt;i++){
            cin>>data[i];
    }
    cout<<"\nAll possible combinations of data elements : \n";
    perm(data,0,cnt);
    cout<<"\nPress any key to exit";
    getch();
    return 1;

}

void swap(int data[],int i,int j){
    int tmp=data[i];
    data[i]=data[j];
    data[j]=tmp;
}
