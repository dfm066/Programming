#include<iostream>
using namespace std;


class date
{
    protected:
        int dt;
        int month;
        int yr;


};
class adm_date: public date
{
    public:
        void get_adm_date()
        {
            cout<<"date=";
            cin>>dt;
            cout<<"month=";
            cin>>month;
            cout<<"year=";
            cin>>yr;
        }
        void put_adm_date()
        {
            cout<<dt<<"/"<<month<<"/"<<yr<<endl;
        }
};

class dis_date: public date
{
    public:
        void get_dis_date()
        {
            cout<<"date=";
            cin>>dt;
            cout<<"month=";
            cin>>month;
            cout<<"year=";
            cin>>yr;
        }
        void put_dis_date()
        {
            cout<<dt<<"/"<<month<<"/"<<yr<<endl;
        }
};

class disease
{
    protected:
        char disease_[40];
        public:
            void get_disease()
            {
                cin>>disease_;
            }
            void put_disease()
            {
                cout<<disease_<<endl;
            }
};

class patient:public adm_date,public dis_date,public disease
{
    protected:
        char name[20];
    public:
        void get_name()
        {
            cin>>name;
        }
        void put_name()
        {
            cout<<name;
        }
        void display()
        {
            cout<<"Patient's name=";
            put_name();
            cout<<"\nadmission date";
            put_adm_date();
            cout<<"\nDisease=";
            put_disease();
            cout<<"\ndischarge date";
            put_dis_date();
        }

};


int main()
{
    patient s[10];
    int x,i=0,counter=0;
    char tmp_name[20];
    while(1)
    {
        cout<<"\n1.Enter Patient's data\n2.get patient's data\n3.exit\nchoice=";
        cin>>x;
        if(x>3)
        {break;}
        switch(x)
        {
            case 1:
                i=counter;
                cout<<"Enter Patient's name=";
                s[i].get_name();
                cout<<"Enter admission date\n";
                s[i].get_adm_date();
                cout<<"Disease=";
                s[i].get_disease();
                cout<<"Enter discharge date\n";
                s[i].get_dis_date();
                i++;
                counter=i;
                break;
            case 2:

                if(counter==0)
                {
                    cout<<"no patient is in hospital\n";
                }
                else
                {
                    cout<<"names of all patients\n";
                    for(i=0;i<counter;i++)
                    {
                        cout<<i+1<<".";
                        s[i].put_name();
                        cout<<"\n";
                    }
                    cout<<"which patient's data you want=";
                    cin>>i;
                    s[i-1].display();
                    break;
                }



        }
    }


    return 1;
}
