//program for hospital data + age ditection
//under 12 or not

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
class AGE
{
    protected:
        int age;
    public:
        void get_age()
        {
            cout<<"Age=";cin>>age;
        }

        int put_age()
        {
            return(age);
        }
};
class patient:public adm_date,public dis_date,public disease,public AGE
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
            cout<<"\nage="<<age;

        }

};


int main()
{
    patient s[10];
    int x,i=0,counter=0,j=0,age;
    char tmp_name[20];
    while(1)
    {
        cout<<"\n1.Enter Patient's data\n2.get patient's data\n3.pediatric patients less than 12 yrs\n4.exit\nchoice=";
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
                s[i].get_age();
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
            case 3:
                for(i=0;i<counter;i++)
                    {
                        age=s[i].put_age();
                        if(age<=12)
                        {
                            j++;
                            cout<<j<<".";
                            s[i].put_name();
                            cout<<"\n";
                        }
                    }
                    if(j==0)
                    {
                        cout<<"\nthere is no patient below 12 yrs\n";
                    }



        }
    }


    return 1;
}

