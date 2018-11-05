#include "utils.h"

using namespace std;

int main() {
    int n;
    matrix<bigint> res; 
    cout << "Enter value of N : ";
    cin >> n;
    cout << "\n" << n <<"th fibonacci number is  : " << nth_fib(n, res) << endl;
    return 0;
}