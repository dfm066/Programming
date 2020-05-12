#include "utils.h"

using namespace std;
vector<int> primes2n_v2(int n) {
  vector<bool> num_map(n + 1);
  vector<int> primes;

  fill(begin(num_map), end(num_map), true);
  primes.reserve(sqrt(n));

  for (int i = 2; i <= sqrt(n); ++i) {
    if (num_map[i]) {
      for (int sq = i * i, j = sq, k = 1; j <= n; ++k) {
        num_map[j] = false;
        j = sq + k * i;
      }
    }
  }

  for (int i = 2; i <= n; ++i) {
    if (num_map[i])
      primes.push_back(i);
  }

  return primes;
}

void print_vector(const vector<int> &p, const string &s) {
	cout << s ;
	for (auto val : p) {
		cout << val << " ";
	}
	cout << endl;
}

int main(){
	auto st = GET_HRTIME();
	const int sz = 1000000;
	vector<int> primes = primes2n(sz);
	auto en = GET_HRTIME();
	time_diff	diff_v1 = en - st;
	st = GET_HRTIME();
	vector<int> primes_v2 = primes2n_v2(sz);
	en = GET_HRTIME();
	time_diff	diff_v2 = en - st;
	if (primes_v2.size() == primes.size())	cout << "Correct" << endl;
	else cout << "Incorrect!" << endl;
	cout << "Time to execute v1 : " << ms(diff_v1).count() << "ms\t" 
       << us(diff_v1).count() << "us\t" << ns(diff_v1).count() << "ns\n" <<  endl;
	cout << "Time to execute v2 : " << ms(diff_v2).count() << "ms\t" 
		<< us(diff_v2).count() << "us\t" << ns(diff_v2).count() << "ns\n" <<  endl;

	// print_vector(primes, "Version 1 Prime : ");
	// print_vector(primes_v2, "Version 2 Prime : ");
	
	return 0;
}