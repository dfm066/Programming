/*
Name : DFM066
Problem 1
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define BIG unsigned long long
#define MAX 1000000000
using namespace std;



int main() {
    int T;
    BIG sum = 0;
    cin>>T;
    int N;
    while(T--){
        cin>>N;
        N = N-1;
        sum = (N/3*(3+N/3*3))>>1;
        sum += (N/5*(5+N/5*5))>>1;
        sum -= (N/15*(15+N/15*15))>>1;
        cout<<sum<<endl;;
    }
    return 0;
}

