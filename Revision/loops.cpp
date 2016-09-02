#include<iostream>
using namespace std;

int main(){
    int no,new_no,sz=0,first=0,last=0,div=1;
    cout<<"\nEnter No : ";
    cin>>no;
    while(no/div>0){
        sz++;
        div*=10;
    }
    div/=10;
    first=no/div;
    last=no%10;
    new_no=(last*div)+(((no%div)/10)*10+first);
    cout<<"\nNew No : "<<new_no;
    return 0;
}
