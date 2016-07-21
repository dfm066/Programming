/*
Name : DFM066
Problem 1
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include<iostream>
using namespace std;
int main(){
    int sum=0;
    int i;
    for(i = 1; i*3 < 1000; sum+=i*3,i++);
    for(i = 1; i*5 < 1000;sum+=i*5,i++);
    for(i = 1; i*15 < 1000;sum-=i*15,i++);

    cout<<sum;
    return 0;
}
