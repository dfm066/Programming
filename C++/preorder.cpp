#include<iostream>
#include "Headers/btree.cpp"
using namespace std;
int main(){
    btree b1;
    cout<<"Enter Binary Tree : ";
    int key=1;
    while(1){
        cin>>key;
        if(key==0)
            break;
        b1.insert(key);
    }
    b1.preorder();
    return 0;
}
