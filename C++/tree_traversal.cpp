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
    cout<<"\nPreorder : ";
    b1.preorder();
    cout<<"\nInorder : ";
    b1.inorder();
    cout<<"\nPostorder : ";
    b1.postorder();
    return 0;
}
