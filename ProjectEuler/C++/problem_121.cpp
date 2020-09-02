#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>

using ll = long long;

ll problem_121(int round) {
    int limit = (round-1)>>1;
    std::vector<ll> rounds(limit+1);
    rounds[0] = 1;
    // Ordinary Generating Function
    // f(x)= r∑0 c x^n
    // n is the number of round won
    // c is the number of ways to win n rounds
    // here rounds[i] is x ^ n-i th round
    for(int n = 0 ; n <= round; ++n) {
        for(int c = limit; c > 0; --c) {
            rounds[c] += n * rounds[c-1];
        }
    }

    ll D = 1;
    for(int i = 2; i <= round+1; ++i) D *= i;
    return D / std::accumulate(rounds.begin(), rounds.end(), ll(0));
}

int main(int argc, char const *argv[])
{
    int round = 0;
    std::cin >> round;
    std::cout << problem_121(round) << std::endl;
    return 0;
}
