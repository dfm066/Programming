#include <iostream>
#include <cmath>
using namespace std;

double round_up(double x, double precision) {
    long long fixed_precision = x / precision;
    x = fixed_precision * precision;
    return x;
}

// Finds the nth root of the x within +/- 10^(-precision) error range
// Complexity of the algorithm is O(log(n) * log(x*(10^precision)))
// Assumption provide that pow fn has Complexity log(n).
pair<double, long long> nth_root(double x, int n, int precision) {
    double ans = 0;
    double err = pow(10, -precision);
    double st = 0;
    double en = ceil(x);
    double delta = 0;
    double approx = 0;
    long long steps = 0;
    while (st <= en) {
        ans = (st+en)/2;
        approx = pow(ans, n);
        delta = abs(x-approx);
        if (delta <= err) break;
        if (approx > x) en = ans - err;
        else st = ans + err;
        steps++;
    }
    ans = round_up(ans, err);
    return {ans, steps};
}

// Mathematical formulae
double nth_root(double x, int n) {
    return exp(log(x)/n);
}

int main() {
	double x;
	int n;
	int precision;
	cin >> x >> n >> precision;
	auto sol = nth_root(x, n, precision);
	cout << "Nth root : " << sol.first << " found after " << sol.second << " guesses." << endl;
	cout << "Nth root (using math) : " << nth_root(x, n) << endl;
	return 0;
}
