#include<string>
#include<iostream>
using namespace std;


class employee
{
    int Empno;
    char Ename[100];
    float basic,HRA,DA,Netpay,gross,fund;
public:
    void getdata()
    {
        cout<<"Enter Employee no=";
        cin>>Empno;
        cout<<"enter name of employee=";
        cin>>Ename;
        cout<<"Basic=";
        cin>>basic;
        cout<<"amount of  provident fund & insurance=";
        cin>>fund;
    }
    int put_Empno()
    {
        return(Empno);
    }
    void calculate()
    {
        HRA=basic*0.1;
        DA=basic*0.2;
        gross=basic+ HRA + DA;
        Netpay=gross-fund;

    }
    void putdata()
    {
        cout<<"\nEmployee Number="<<Empno;
        cout<<"\nname of employee="<<Ename;
        cout<<"\nNet salary="<<Netpay;
    }
};

int main()
{
    employee a[10];
    int i=0,counter=0,x,num,tmp;
    while(1)
    {
        cout<<"\n\n1.store information of employee\n2.get information of employee\n3.exit\n=";
        cin>>x;
        if(x>2)
        {
            break;
        }
        switch(x)
        {
        case 1:
            i=counter;
            a[i].getdata();
            i++;
            counter=i;
            break;
        case 2:
            cout<<"Enter Employee Id Number=";
            cin>>num;
            i=0;
            while(1)
            {
                if(i>counter)
                {
                    cout<<"\nEmployee data is not present";
                    break;
                }
                tmp=a[i].put_Empno();
                if(num==tmp)
                {
                    a[i].calculate();
                    a[i].putdata();
                    break;
                }

               i++;
            }

            break;

        }
    }

}
