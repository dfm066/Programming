//Write a program to read and write data in a text file.
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream getf("student");           //opening file
	char nm[30];
	cout<<"\nenter name=";
	cin>>nm;
	getf<<nm<<"\n";         //name stored in file

	int roll_no;
	cout<<"Enter roll no=";
	cin>>roll_no;
	getf<<roll_no<<"\n";            // roll no stored in file

	float mrk;
	cout<<"Enter marks=";
	cin>>mrk;
	getf<<mrk<<"\n";                //marks stored in file
	getf.close();                   //closing file
    //getting data from file
	ifstream inf("student");        //opening file in read mode
	inf>>nm;
	inf>>roll_no;
	inf>>mrk;

	cout<<"\nName="<<nm<<"\nroll no="<<roll_no<<"\nmarks="<<mrk<<"\n";
	inf.close();
	return 0;
}

