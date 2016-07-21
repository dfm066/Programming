#include<iostream>
using namespace std;
class time
{
    int h,m;
public:
    time()
    {
        cout<<"\nEnter time(hours minutes): ";
        cin>>h>>m;
    }
    time(time &t)
    {
            *this=time();
            while(this->m>60)
            {
                this->h+=1;
                this->m-=60;
            }
            while(t.m>60)
            {
                t.h+=1;
                t.m-=60;
            }
            this->h+=t.h;
            this->m+=t.m;
            while(this->m>=60)
            {
                this->h+=1;
                this->m-=60;
            }
    }
    void display()
    {
        cout<<"\nAddition of time: "<<h<<":"<<m;
    }
};
int main()
{
    time p;
    time q(p);
    q.display();
    return 0;
}



