#include<iostream>
using namespace std;
class student
{
protected:
    int rno;
public:
    void getno(int no)
    {
        rno=no;
    }
    void putno()
    {
        cout<<"\nRoll Number: "<<rno<<endl;
    }
};
class test:virtual public student
{
    protected:
        int part1,part2;
    public:
        void get_marks(float x,float y)
        {
            part1=x;
            part2=y;
        }
        void put_marks()
        {
            cout<<"\nMarks obtained: "<<"\n"<<"part1="<<part1<<"part2="<<part2<<endl;

        }
};
class sports:virtual student
{
protected:
    int score;
public:
    void get_score(float sc)
    {
        score=sc;
    }
    void put_score()
    {
        cout<<"\nsport score: "<<score;
    }
};
class result:public test,public sports
{
    public:
        void display()
        {
            putno();
    cout<<"\nResult: ";
    put_marks();
    put_score();
    cout<<"\nTotal: "<<(score+part1+part2);
        }

};
int main()
{
    result s;
    s.getno(241);
    s.get_marks(99,98);
    s.get_score(99);
    s.display();
    return 0;
}
