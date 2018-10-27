#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b,a%b);
}
int main() {
   cout << gcd (27,45);
    return 0;
}
