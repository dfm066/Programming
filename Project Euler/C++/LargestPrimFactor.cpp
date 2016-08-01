
/*
Name : DFM066
Problem 3
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include<iostream>
#include <vector>
using namespace std;

int main(){

    long long q = 600851475143; // minimum value
    vector<long long> factors;
    for(long long i = 2; i<=q; i++){
        if(q%i==0){
            factors.push_back(i);
            q/=i;
            i=2;
        }
    }
    for(auto i:factors)
        cout<<i<<" ";
    cout<<factors.back();
    return 0;
}
