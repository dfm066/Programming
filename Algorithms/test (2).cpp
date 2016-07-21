#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n,flag=0,i,k;
    int number;
    cin>>n;
    while(n--)
    {
        cin>>number;
        k=sqrt(number);
        for(i=2;i<=k;i++)
        {
            if(number%i==0){
                cout<<"no"<<endl;
                break;
            }

        }
        if(number<=1)
            cout<<"no"<<endl;
        else if(i>k)
            cout<<"yes"<<endl;
    }
}
