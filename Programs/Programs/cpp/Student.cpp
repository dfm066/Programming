#include<iostream>
using namespace std;

class student
{
    protected:
        char Name[20];
        int roll_no;
    public:
        void get_info()
        {
            cout<<"Enter Name=";cin>>Name;
            cout<<"roll no=";cin>>roll_no;
        }
        int put_roll_no()
        {
            return(roll_no);
        }

};

class test:public student
{
    protected:
        float sub1,sub2,sub3;
    public:
        void get_score()
        {
            cout<<"Physics=";cin>>sub1;
            cout<<"Chemistry=";cin>>sub2;
            cout<<"Maths=";cin>>sub3;
        }
};

class result: public test
{
    protected:
        float total,percentage;
    public:
        void calculate()
        {
            total=sub1 +sub2+sub3;
            percentage=total/3;
        }

        void display()
        {
            cout<<"\nroll no="<<roll_no;
            cout<<"\nName="<<Name;
            cout<<"\nMarks of Each subjects";
            cout<<"\nPhysics="<<sub1<<"\tChemistry="<<sub2;
            cout<<"\tMaths="<<sub3;
            cout<<"\nTotal="<<total;
            cout<<"\npercentage="<<percentage<<"%\n\n";

        }
};

int main()
{
    int i=0,counter=0,x,num,tmp;
    result student_[10];
    while(1)
    {
        cout<<"\n1.Enter Info of data\n2.get the info of data\n3.exit\nchoice=";

        cin>>x;
        if(x>2)
        {
            break;
        }
        switch(x)
        {
            case 1:
                i=counter;
                student_[i].get_info();
                student_[i].get_score();
                i++;
                counter=i;
                break;
            case 2:
                cout<<"Enter student's roll Number=";
                cin>>num;
                i=0;
                while(1)
                {
                    if(i>counter)
                    {
                        cout<<"\nStudent's data is not present";
                        break;
                    }
                    tmp=student_[i].put_roll_no();
                    if(num==tmp)
                    {
                        student_[i].calculate();
                        student_[i].display();
                        break;
                    }

                    i++;
                }
                break;



        }
    }
    return(0);
}
