#include <iostream>
#include <string>
#include "utils.cpp"

using namespace std;

int main(){
	vector<int> primes = primes2n(200);
	int pos = 0;
	while(primes[pos] != 131) ++pos;
	cout << pos;
}