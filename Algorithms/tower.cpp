#include<iostream>
using namespace std;

void tower(int n,char a,char b,char c){
    if(n>=1){
        tower(n-1,a,c,b);
        cout<<"Move top disk from tower "<<a<<" to tower"<<b<<endl;
        tower(n-1,c,b,a);
    }
}

int main(){
    int dc=0;
    cout<<"\nEnter disk count : ";
    cin>>dc;
    cout<<"Steps to move "<<dc<<" disks from tower A to B with the help of tower C : \n";
    tower(dc,'A','B','C');
}
