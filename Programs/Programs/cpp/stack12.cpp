//create stack. use operator overloading for push pop and display


#include<iostream>
using namespace std;
int i=-1;
class stack
{
    int arr[100];
public:
    int operator+(int d)
    {
       if(i>99)
        {
           cout<<"\nStack overflow";
        }
       else
        {
            i++;
            arr[i]=d;
        }
        return 0;
    }
    int operator-(int d)
    {
        d=arr[i];
        i--;
        cout<<"\ndata poped="<<d<<endl;
        return 0;
    }
    void print()
    {
        if(i==-1)
        {
            cout<<"\nstack is underflow\n";
        }
        else
        {
            for(int z=0;z<=i;z++ )
            cout<<arr[z]<<" ";
        }

    }
};

int main()
{
    int data,x,flag=0;
    stack a;
    while(1)
    {
        cout<<"\n1.push\n2.pop\n3.print\n4.exit\n";
        cin>>x;
        switch(x)
        {
        case 1:
            cout<<"data=";
            cin>>data;
            a+data;
            break;
        case 2:
            a-data;
            break;
        case 3:
            a.print();
            break;
        case 4:
            flag=1;
            break;
        default:
            cout<<"wrong input";
        }
        if(flag==1)
        {
            break;
        }

    }

}
