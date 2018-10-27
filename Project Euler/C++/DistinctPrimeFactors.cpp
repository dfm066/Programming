<<<<<<< HEAD
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "utils.h"

using namespace std;

int main(){
	const int limit = 2 * 10e6;
	vector<int> primes = primes2n(sqrt(limit)+1);
    const int start[3] = {14, 644, 134043};
    vector<uint16_t> numbers(limit+4);
    vector<int> factors;
    factors.reserve(32);
    fill(begin(numbers), end(numbers), 0);
	int n;
	int k;
    int fact;
    unsigned long long  num;
    int rng;
    int counter = 0;
	rng = scanf("%d%d",&n,&k);
	for(int i = start[k-2]; i <= n+k-1; ++i){
        if(!numbers[i]){
            num = i;
            rng = sqrt(i);
            factors.clear();
            for(int j = 0; primes[j] <= rng; ++j ){
                if(num % primes[j] == 0){
                    factors.push_back(primes[j]);
                    num /= primes[j];
                    while( num % primes[j] == 0)    num /= primes[j];
                }
            }
            if(num != 1)    factors.push_back(num);
            num = i;
            fact = factors.size();
            numbers[num] = fact;
            for(int j = 0; j < fact; j++){
                for(int e = 1;; ++e){
                    num = i * pow(factors[j],e);
                    if(num < n+k)    numbers[num] = fact;
                    else break;
                }
            }
            for(int e = 2;;++e){
                num = pow(i, e);
                if(num < n+k)    numbers[num] = fact;
                else break;
            }
        }
    }
    int cons = 0;
    int sz = numbers.size();
    for(int i = start[k-2]; i <= n + k - 1; ++i){
        if(numbers[i] == k){
            ++cons;
            ++counter;
            if(cons >= k) rng = printf("%d\n",i - k + 1);
        } else {
            cons = 0;
        }
    }
    //printf("\n%d\n",counter);
    //for(int i = start[k-2]; i <= n + k - 1; ++i) cout << numbers[i] << " ";
=======
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "utils.cpp"

using namespace std;

int main(){
	const int limit = 2 * 10e6;
	vector<int> primes = primes2n(sqrt(limit)+1);
    const int start[3] = {14, 644, 134043};
    vector<uint16_t> numbers(limit+4);
    vector<int> factors;
    factors.reserve(32);
    fill(begin(numbers), end(numbers), 0);
	int n;
	int k;
    int fact;
    unsigned long long  num;
    int rng;
    int counter = 0;
	rng = scanf("%d%d",&n,&k);
	for(int i = start[k-2]; i <= n+k-1; ++i){
        if(!numbers[i]){
            num = i;
            rng = sqrt(i);
            factors.clear();
            for(int j = 0; primes[j] <= rng; ++j ){
                if(num % primes[j] == 0){
                    factors.push_back(primes[j]);
                    num /= primes[j];
                    while( num % primes[j] == 0)    num /= primes[j];
                }
            }
            if(num != 1)    factors.push_back(num);
            num = i;
            fact = factors.size();
            numbers[num] = fact;
            for(int j = 0; j < fact; j++){
                for(int e = 1;; ++e){
                    num = i * pow(factors[j],e);
                    if(num < n+k)    numbers[num] = fact;
                    else break;
                }
            }
            for(int e = 2;;++e){
                num = pow(i, e);
                if(num < n+k)    numbers[num] = fact;
                else break;
            }
        }
    }
    int cons = 0;
    int sz = numbers.size();
    for(int i = start[k-2]; i <= n + k - 1; ++i){
        if(numbers[i] == k){
            ++cons;
            ++counter;
            if(cons >= k) rng = printf("%d\n",i - k + 1);
        } else {
            cons = 0;
        }
    }
    //printf("\n%d\n",counter);
    //for(int i = start[k-2]; i <= n + k - 1; ++i) cout << numbers[i] << " ";
>>>>>>> d46bd7a2e9d0e8f834f59714658ed2f1ed5960bd
}