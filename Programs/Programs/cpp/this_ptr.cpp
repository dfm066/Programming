#include<iostream>
using namespace std;
int i=1;
class cmp
{
    int age;
public:
    cmp()
    {
        cout<<"\nEnter age"<<i<<":";
        cin>>age;
        i++;
    }
    cmp(cmp &t)
    {
        *this=cmp();
        cout<<"Age "<<(this->age>t.age?this->age:t.age)<<" is max...";
    }
};
int main()
{
    cmp p;
    cmp q(p);
    return 0;
}
