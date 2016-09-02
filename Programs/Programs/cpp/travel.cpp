#include<iostream>
using namespace std;

class stations
{
    protected:
        char from_station[50];
        char to_station[50];
        int distance;
    public:
        void get_stations()
        {
            cout<<"\nFrom=";
            cin>>from_station;
            cout<<"To=";
            cin>>to_station;
            cout<<"distance between two stations=";
            cin>>distance;
        }
        void display_station()
        {
            cout<<"\nFrom="<<from_station<<"\tTo="<<to_station<<"\ndistance="<<distance<<"KM"<<endl;
        }
};


class travel: public stations
{
    char name[50];
    int no_of_people;
    int no_of_bus;
    int total;
    int fare_per_km;
    public:
        void calculate()
        {
            if(no_of_people% 50==0)
            {
                no_of_bus=no_of_people/50;
            }
            else
            {
                 no_of_bus=no_of_people/50 + 1;
            }

            total=distance*no_of_bus*fare_per_km;
        }

        void get_data()
        {
            cout<<"Name=";
            cin>>name;
            cout<<"number of people travelling=";
            cin>>no_of_people;
            cout<<"Enter Source and destination";
            get_stations();
            cout<<"fare per km=";cin>>fare_per_km;
        }

        void display_ticket()
        {
            cout<<"\nName="<<name;
            cout<<"\nnumber of people travelling="<<no_of_people;
            cout<<"\nEnter Source and destination";
            display_station();
            cout<<"no of buses required="<<no_of_bus;
            cout<<"\nfare per km="<<fare_per_km;
            cout<<"\nTotal cost="<<total<<endl;
        }
        void put_name()
        {
            cout<<name;
        }
};

int main()
{
    travel s[10];
    int x, i=0,counter=0;
    while(1)
    {
        cout<<"\n\n1.enter new entry\n2.print ticket\n3.exit\nchoice=";
        cin>>x;
        if(x>2)
        break;
        switch(x)
        {
            case 1:
                counter=i;
                s[i].get_data();
                i++;
                counter=i;
                break;
            case 2:
                if(counter==0)
                {
                    cout<<"\nThere no entry\n";
                }
                else
                {
                    cout<<"\nNames of customers\n";

                    for(i=0;i<counter;i++)
                    {
                        cout<<"\n"<<i+1<<".";
                        s[i].put_name();
                    }
                    cout<<"\nwhoose ticket should be printed?";
                    cin>>i;
                    s[i-1].calculate();
                    s[i-1].display_ticket();
                    break;
                }

        }
    }
}
















