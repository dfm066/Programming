#include <iostream>
using namespace std;
int main(){
    string str;

    cin>>str;
    cout<<endl;
    for(int i =0 ; str[i]!='\0';i++){
        cout<<str[i]+2;
    }

    return 0;
}
