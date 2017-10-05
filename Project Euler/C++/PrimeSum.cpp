#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

ull power(ull x, ull y, ull p)
{
    int res = 1;      
    x = x % p;  
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
 
bool miillerTest(int d, int n)
{
    int a = 2 + rand() % (n - 4);
    int x = power(a, d, n);
    
    if (x == 1  || x == n-1)
       return true;
    
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
 
    return false;
}

bool isPrime(int n, int k)
{
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
 
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    
    for (int i = 0; i < k; i++)
         if (miillerTest(d, n) == false)
              return false;
 
    return true;
}

std::vector<int> primes2n (int n)
{
    std::vector<bool> num_map(n+1);
    std::vector<int> primes;

    std::fill(std::begin(num_map), std::end(num_map), true);
    primes.reserve(sqrt(n));
    
    for(int i = 2; i <= sqrt(n); ++i){
        if(num_map[i]){
            for(int sq = i*i,j = sq,k = 1; j <= n; ++k){
                num_map[j] = false;
                j = sq + k * i;
            }
        }
    }

    for(int i = 2; i <= n; ++i){
        if(num_map[i])  primes.push_back(i);
    }
    
    return primes;
}

int main(){
    int T;
    int N;
    vector<int> primes = primes2n(10000000);
    cin >> T;
    int sz = primes.size();
    int lm = 32;
    while(T--){
        cin >> N;
        int terms = 0;
        int p = 0;
        int c = 0;
        ull s = 0;
        for(int i = 0,j; i < 32; ++i){
            s = 0;
            c = 0;
            for(j = i; ; ++j){
                s += primes[j];
                if(s > N){
                    s -= primes[j];
                    break;
                }
                ++c;
                if(isPrime(s,4)){
                    if(c > terms){
                        terms = c;
                        p = s;
                    }
                }
            }
        }
        cout << p << " " << terms << endl;
        
    }
}

