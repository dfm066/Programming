//Write a program to read and write data in a binary file.

#include<iostream>
#include<fstream>
using namespace std;
class emp         //Declaring Class of Employee
{
	int emp_no;
	char name[20];
	float salary;
  public:
  	void get()                 //to get data of employee
	{
	    cout<<"enter Information of Employee\n";
		cout<<"Employee no=";cin>>emp_no;
		cout<<"Name=";cin>>name;
		cout<<"Salary=";cin>>salary;
	}
	void display()                 //display data of employee
	{
		cout<<"Information of Employee\n";
		cout<<"Employee no="<<emp_no;
		cout<<"\nName="<<name;
		cout<<"\nSalary="<<salary;
	}
};
int main(void)
{
	ofstream empfile("employee.bin",ios::in|ios::binary);                    //opening file in binary , input mode
	emp e;
	int n,i;
	e.get();
	empfile.write((char *)&e,sizeof(e));
	empfile.close();
	ifstream empfile1("employee.bin",ios::in|ios::binary);
	empfile1.read((char *)&e,sizeof(e));
	e.display();
	empfile1.close();
	return 0;
}
