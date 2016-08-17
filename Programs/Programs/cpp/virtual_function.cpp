#include<iostream>
using namespace std;
class shape
{
    public:
    virtual void display()
    {
        cout<<"\nArea calculated are : ";
    }
};
class triangle:public shape
{
    float h,b,ar;
    public:
    triangle()
    {
        cout<<"\nEnter height and base of triangle: ";
        cin>>h>>b;
        ar=0.5*h*b;
    }
    void display()
    {
        cout<<"\n1.Triangle: "<<ar<<"sq.units";
    }
};
class circle:public shape
{
    float r,ar;
    public:
    circle()
    {
        cout<<"\nEnter radius: ";
        cin>>r;
        ar=3.142*r*r;
    }
    void display()
    {
        cout<<"\n2.Circle: "<<ar<<"sq.units";
    }
};
class rectangle:public shape
{
    float h,b,ar;
    public:
    rectangle()
    {
        cout<<"\nEnter lenght and width of rectangle: ";
        cin>>h>>b;
        ar=h*b;
    }
    void display()
    {
        cout<<"\n3.Rectangle: "<<ar<<"sq.units";
    }
};
int main()
{
    shape *b,x;
    triangle t;
    circle c;
    rectangle r;
    b=&x;
    b->display();
    b=&t;
    b->display();
    b=&c;
    b->display();
    b=&r;
    b->display();
    return 0;
}
