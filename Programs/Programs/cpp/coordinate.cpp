//program to get coordinate and get distance from origin
#include<math.h>
#include<iostream>
using namespace std;

class cooridinate
{
    protected:
        int x,y;
    public:
        void get_cord()
        {
            cout<<"enter co-ordinates\nx=";cin>>x;
            cout<<"y=";cin>>y;
        }
        void disp_cord()
        {
            cout<<"\nx="<<x<<"\ty="<<y;
        }
};

class distance_:public cooridinate
{
    protected:
        float dist;
    public:
        void display()
        {
            disp_cord();
            dist=x*x +y*y;
            dist=sqrt(dist);
            cout<<"\nDistance from origin="<<dist;
        }
};

int main()
{
    distance_ d;
    int opt;

    while(1)
    {
        cout<<"\n1.Enter the co-ordinates\n2.distance from origin\n3.exit\nchoice=";
        cin>>opt;
        if(opt>2)
        {
            break;
        }
        switch(opt)
        {
            case 1:
                d.get_cord();
                break;
            case 2:
                d.display();
                break;
        }
    }

}
