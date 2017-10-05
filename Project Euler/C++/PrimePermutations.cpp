#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

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

int main() {
    const int start = 1487;
    int n,k;
    cin >> n >> k;
    int req = to_string(n).size() - 1;
    int mult = n / int(pow(10, req));
    if(mult > 1)    ++req;
    int sz = int(pow(10, req));
    vector<int> primes = primes2n(sz);
    vector<bool> prime_map(sz);
    fill(begin(prime_map), end(prime_map), true);
    int pos = 0;
    int limit = primes.size();
    while(primes[pos] != start){
      //  prime_map[primes[pos]] = false;
        ++pos;
    }
	vector<int> ap;
    ap.reserve(150);
    vector<string> sap;
    sap.reserve(150);
    int width, prev_width;
    prev_width = width = k+1;
    for(int i = pos; i < limit && primes[i] < n; ++i){
        if(prime_map[primes[i]]){
            string  snum = to_string(primes[i]);
            width = snum.size();
            int counter;
            int num;
            ap.clear();
			ap.push_back(primes[i]);
            while(next_permutation(begin(snum), end(snum))){
                num = stoi(snum);
                if(num % 2 != 0 && binary_search(begin(primes), end(primes), num)) {
                    ap.push_back(num);
                    prime_map[num] = false;
                }
            }
            counter = ap.size();
            if(counter >= k) {
				for (int m=1; m < counter-1; ++m)
				{
					int l = m-1, r = m+1;
					while (l >= 0 && r <= counter-1)
					{
						if (ap[l] + ap[r] == 2*ap[m]){
							if(k == 3)	
                            {
                                sap.push_back(to_string(ap[l])+to_string(ap[m])+to_string(ap[r]));
                            }
							else{
								int last = ap[r] + ap[m] - ap[l];
								if(binary_search(begin(ap), end(ap), last)){
									sap.push_back(to_string(ap[l])+to_string(ap[m])
                                                  +to_string(ap[r])+to_string(last));
								}
							}
 						}
						(ap[l] + ap[r] < 2*ap[m]) ? ++r : --l;
					}
				}
			}
        }
        if(width != prev_width){
            prev_width = width;
            sort(begin(sap), end(sap));
            for(const auto& ans : sap)  cout << ans << endl;
            sap.clear();
        }
    }
    sort(begin(sap), end(sap));
    for(const auto& ans : sap)  cout << ans << endl;
    return 0;
}