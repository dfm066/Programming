/*
Name : DFM066

Problem 2
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

#include<iostream>
using namespace std;

int main(){
    int n1 = 1;
    int n2 = 2;
    int fib,sum=2;
    while(fib<=4000000){
        fib = n1+n2;
        n1  = n2;
        n2  = fib;
        if(fib%2==0)
            sum+=fib;
    }
    cout<<sum;
    return 0;
}
