/*
Name : DFM066
Problem 1
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include<iostream>
using namespace std;
int main(){
    unsigned long long sum=0;
    unsigned long long N = 1000000000;
    for(auto i = 1; i*3 < N; sum+=i*3,i++);
    for(auto i = 1; i*5 < N;sum+=i*5,i++);
    for(auto i = 1; i*15 < N;sum-=i*15,i++);

    cout<<sum;
    return 0;
}
