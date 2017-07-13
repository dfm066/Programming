#include <iostream>
#include <cmath>

#define MAX 100000
using namespace std;

int main(){
    int N;
    unsigned long long dist = 0;
    int contri[MAX+1];
    cin >> N;
    int maxpow = floor(log2(N));
    int maxbase = floor(sqrt(N));
    int exp_map[32];
    exp_map[1] = N-1;
    exp_map[2] = N - N/2;
    for(int e2 = 2; e2 <= N; ++e2){
        contri[e2] = 1;
        for(int e1 = 3; e1 <= maxpow; ++e1){
            int curr_e = e2 * e1;
            if(curr_e > N){
                int counter = 2;
                for(int m = 2; m < e1; ++m){
                    if(curr_e > m * N || curr_e % m != 0) ++counter;
                }
                if(counter == e1)   ++exp_map[e1];
            }
        }
    }
    for(int i = 2; i <= maxbase; ++i){
        for(int j = 2; j <= maxpow; ++j){
            int tmp = floor(pow(i, j));
            if (tmp <= N ) {
               if(contri[tmp] < j)  contri[tmp] = j;
            } else break;
        }
    }
    for(int i = 2; i <= N; ++i) dist += exp_map[contri[i]];
    cout <<  dist << endl;
}