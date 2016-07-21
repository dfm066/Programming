#include <iostream>
using namespace std;

int fib(int no){
    if(no<=1){
        return no;
    }
    else{
        return fib(no-1)+fib(no-2);
    }
}

int main(){
    int no=0,tmp=0;
    cout<<"Enter the series limit : ";
    cin>>no;
    cout<<"\nFibonacci series :";
    for(int i=0;;i++){
            tmp=fib(i);
            if(tmp<=no){
                cout<<"\t"<<tmp;
            }
            else{
                break;
            }
    }

    return 0;
}
