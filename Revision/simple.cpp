#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int x = 10;
	int *p = &x;
	int &m = *p;
	cout<<"M : "<<m<<"\tP : "<<p<<"\tX : "<<x;
	return 0;
}