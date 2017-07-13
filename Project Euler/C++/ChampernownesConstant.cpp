#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
const ull MAX = 10e18;

int main() {
    vector<ull> start;
    vector<ull> dig_cnt;
    vector<ull> dig_val;

    start.reserve(16);
    dig_cnt.reserve(16);
    dig_val.reserve(16);
    ull cnt = 0;
    ull prod = 0;
    dig_val.emplace_back(0);
    dig_cnt.emplace_back(0);
    start.emplace_back(0);
    
    for(ull mult = 1, dig = 1; cnt < MAX; dig += 1, mult *= 10){
        prod = 9 * mult;
        cnt += prod * dig;

        dig_cnt.push_back(prod);
        dig_val.push_back(cnt);
        start.emplace_back(mult-1);
    }
    
    int T;
    ull di[7];
    cin >> T;
    while(T--){
        ull exp = 1;
        for(uint8_t i = 0; i < 7; ++i){
            cin >> di[i];
            ull dig_len = 0;
            ull diff = 0;
            ull num = 0;
            ull dig_loc = 0;
            ull dig = 0;
            while(di[i] > dig_val[dig_len]) ++dig_len;
            diff = di[i] - dig_val[dig_len-1];
            num = start[dig_len] + diff / dig_len;
            dig_loc = diff % dig_len;
            dig_loc == 0 ? dig_loc = dig_len - 1, --num : dig_loc -= 1, ++num;
            dig = to_string(num)[dig_loc] - '0';
            exp *= dig;
            //cout << dig_len << " " << diff << " " << start[dig_len] << " " <<  num << " " << dig_loc << " " << dig << endl;
        }
        cout << exp << endl;
    }
    return 0;
}