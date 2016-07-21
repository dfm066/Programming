#include <iostream>
 using namespace std;
 int ackermann(int m,int n){
    if(m==0){
        return n+1;
    }
    if(n==0){
        return ackermann(m-1,1);
    }
    else{
        return ackermann(m-1,ackermann(m,n-1));
    }
 }
 int main(){
    int ans=0;
    int m,n;
    cout<<"Enter values of m and n for ackermann's function : ";
    cin>>m>>n;

    ans=ackermann(m,n);
    cout<<"\nAnswere : "<<ans;
    return 1;
 }
