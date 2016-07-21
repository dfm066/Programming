/*Write a program to pass objects to the function.(Addition of time) Pass the values of time
in hours and minutes And calculate the sum.
For instance: (2 Hours 70 min) (4 Hours 30 minutes) = (7 hours 40 minutes).*/

#include<iostream>
using namespace std;
class time_
{
	int hour,minute;
	public:
		void getdata()
		{
		cin>>hour>>minute;
		}

		void  disp()
		{
		cout<<"Addition of Time="<<hour<<"Hour/s  "<<minute<<"minute/s";
		}

        time_ operator +(time_ C)
        {
        time_ T;
        int temp;
        T.minute=minute+C.minute;
        temp=T.minute/60;
        T.minute=T.minute%60;
        T.hour=hour+C.hour + temp;
        return T;
        }
};
int main()
{
    time_ C1, C2, C3;
    cout<<"enter hours & minutes\n";
    C1.getdata();
    cout<<"enter hours & minutes\n";
    C2.getdata();
    C3=C1+C2;
    C3.disp();

return 0;
}

