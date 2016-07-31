/*
Name : DFM066
Problem 4

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/
#include<iostream>
#include<algorithm>
using namespace std;

bool isPalindrome(int x){
     if((x%10)==((x/100000)%10)&& (x/10)%10==(x/10000)%10 && (x/100)%10==(x/1000)%10)
        return true;
     else
        return false;
}
int main(){
    int no,j;
    for(int i = 0; i < 100; i++){

        for( j = 0; j <= i/2; j++){
            no = (999-j)*(999-i-j);
            if(isPalindrome(no)){
                cout<<no<<" "<<(999-j)<<" "<<(999-i-j);
                break;
            }
        }
        if( j <= i/2)
            break;
    }
    return 0;
}
