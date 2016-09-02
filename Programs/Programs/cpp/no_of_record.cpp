//Write a program to count total number of records in a file.

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class emp                //Declaring Class of Employee
{
	int emp_no;
	char name[20];
	float salary;
  public:
  	void get()            //to get data of employee
	{

		cout<<"\nEmployee no=";cin>>emp_no;
		cout<<"Name=";cin>>name;
		cout<<"Salary=";cin>>salary;
	}
	void display()                //display data of employee
	{
		cout<<"\nEmployee no="<<emp_no;
		cout<<"\nName="<<name;
		cout<<"\nSalary="<<salary;
	}
};
int main(void)
{

	emp e;
	int n=0,i;
	ifstream empfile1("employee",ios::out|ios::binary);              //opening file in binary , output mode
	cout<<"Contents of 'employee' file\n\n";
	empfile1.read((char *)&e,sizeof(e));                    //read the record
	while(!empfile1.eof())
	{
		e.display();                                        //display the record
		empfile1.read((char *)&e,sizeof(e));
		n++;
	}
	cout<<"\nNo of records="<<n;
	empfile1.close();
	return 0;
}
