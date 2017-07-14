#include <cmath>
#include <vector>

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


using ull = unsigned long long;
constexpr ull Modulus = 10000000000ULL;

inline ull modMul(const ull x, const ull y) {
	if (x > (1<<30) && y > (1 << 30))
		return ((x >> 30)*((y << 30) % Modulus) + y*(x & ((1 << 30) - 1))) % Modulus;
	ull z = x*y;
	if (z >= Modulus)
		z %= Modulus;
	return z;
}