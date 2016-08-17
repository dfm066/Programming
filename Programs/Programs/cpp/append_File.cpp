//Write a program to append records to the file.

#include<iostream>

#include<fstream>

#include<iomanip>
using namespace std;

class emp                                               //Declaring Class of Employee

{
	int emp_no;

       char name[20];

        float salary;

        public:

         void get()                                              //to get data of employee

	 {
        cout<<"enter Information of Employee\n";
		cout<<"Employee no=";cin>>emp_no;
		cout<<"Name=";cin>>name;
		  cout<<"Salary=";cin>>salary;

         }

	 void display()                //display data of employee

          {
		cout<<"Information of Employee\n";

    cout<<"Employee no="<<emp_no;

	cout<<"\nName="<<name;
		cout<<"\nSalary="<<salary;

}
};

int main(void)

{

fstream empfile("employee",ios::out|ios::app|ios::binary);	 //opening file in binary append mode read

emp e;

int n,i;

cout<<"\nenter the number  of employes to be append\n";

cin>>n;

cout<<"enter "<<n<<"employes details:";


for(i=0;i<n;i++)                                          //loop to append inform

{

e.get();

empfile.write((char *)&e,sizeof(e));


}

empfile.close();                                         //closing file
	ifstream empfile1("employee",ios::in|ios::binary);          //opening file in binary output mode(read mode)
	cout<<"\nContents of empfile after appending\n";
	empfile1.read((char *)&e,sizeof(e));
	while(!empfile1.eof())
	{
		e.display();
		empfile1.read((char *)&e,sizeof(e));
	}
	empfile1.close();
	return 0;
}
