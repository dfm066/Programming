#include<stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;
class array
{   protected: int x[50];
        public: array()
                {   int i;
                    for(i=0;i<5;i++)
                        x[i]=0;
                }
                void setval(int d,int pos)
                {
                    x[pos]=d;
                }
                int get(int pos)
                {
                    return x[pos];
                }
                void display();
};
void array::display()
{   cout<<"\nData:";
    int i;
    for(i=0;i<5;i++)
        cout<<setw(4)<<x[i];
}
class queue:public array
{   int fr,rr;
    public: queue()
            {   fr=0;
                rr=-1;
            }
            void insque(int);
            void remque();
            void display();
};
void queue::insque(int d)
{   if(rr==50)
    {   cout<<"\nOverflow";
        return;
    }
    setval(d,++rr);
}
void queue::remque()
{   if(rr<fr)
    {   cout<<"\nUnderflow";
        return;
    }
    fr++;
}
void queue::display()
{   if(rr<fr)
    {   cout<<"\nEmpty Queue";
        return;
    }
    cout<<"\nData:";
    int i;
    for(i=fr;i<=rr;i++)
        cout<<setw(4)<<get(i);
}
int main()
{
    queue q;
    int data,opt;
    do
    {
        cout<<"\n1.Enqueue\n2.Dequeue\n3.exit";
        cin>>opt;
            switch(opt)
            {
        case 1:
            cout<<"Enter data: ";
            cin>>data;
            q.insque(data);
            break;
        case 2:q.remque();
            break;
        case 3:
                return 0;
            }
              q.display();
    }while(1);


}


