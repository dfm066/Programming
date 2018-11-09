#include "utils.h"
using namespace std;

int bmap[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

inline int make_cubic_pair(int b0, int b1, int b2, int b3, int b4, int b5) {
    int res = bmap[b0] | bmap[b1] | bmap[b2] | bmap[b3] | bmap[b4] | bmap[b5];
    return res;
}
bool is_valid_comb(int p1, int p2) {
    // remove 9 and replace with 6
    if (p1 & bmap[9])   {
        p1 &= ~ bmap[9];
        p1 |= bmap[6];
    }
    if (p2 & bmap[9])   {
        p2 &= ~ bmap[9];
        p2 |= bmap[6];
    }

    vector<pair<int, int>> combs = {{0,1}, {0,4}, {0,6}, {1,6}, {2,5}, {3,6},
                                    {4,6}, {6,4}, {8,1}};
    for (auto comb: combs) {
        if (!((p1 & bmap[comb.first]) && (p2 & bmap[comb.second])) &&
            !((p1 & bmap[comb.second]) && (p2 & bmap[comb.first])))
            return false;
    }
    return true;
}

int count_cubic_pairs() {
    int cnt = 0;
    for (int bit0 = 0; bit0 < 5; bit0++) 
    for (int bit1 = bit0 + 1; bit1 < 6; bit1++) 
    for (int bit2 = bit1 + 1; bit2 < 7; bit2++) 
    for (int bit3 = bit2 + 1; bit3 < 8; bit3++)
    for (int bit4 = bit3 + 1; bit4 < 9; bit4++)
    for (int bit5 = bit4 + 1; bit5 < 10; bit5++) {
        for (int bit0_s = bit0; bit0_s < 5; bit0_s++) {
            bool bit_flag = (bit0_s == bit0);
            int bit1_s = (bit_flag ? bit1 : bit0_s + 1);
            for (;bit1_s < 6; bit1_s++) {
                bit_flag &= (bit1_s == bit1);
                int bit2_s = (bit_flag ? bit2 : bit1_s + 1);
                for (; bit2_s < 7; bit2_s++) { 
                    bit_flag &= (bit2_s == bit2);
                    int bit3_s = (bit_flag ? bit3 : bit2_s + 1);
                    for (; bit3_s < 8; bit3_s++) { 
                        bit_flag &= (bit3_s == bit3);
                        int bit4_s = (bit_flag ? bit4 : bit3_s + 1);
                        for (; bit4_s < 9; bit4_s++) { 
                            bit_flag &= (bit4_s == bit4);
                            int bit5_s = (bit_flag ? bit5 : bit4_s + 1);
                            for (; bit5_s < 10; bit5_s++) {
                                int cp1 = make_cubic_pair(bit0, bit1, bit2,
                                    bit3, bit4, bit5);
                                int cp2 = make_cubic_pair(bit0_s, bit1_s,
                                    bit2_s, bit3_s, bit4_s, bit5_s);
                                if (cp1 == cp2) {
                                    continue;
                                }
                                if (is_valid_comb(cp1, cp2)) {
                                    cnt++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return cnt;
}
int main () {
    int pairs = count_cubic_pairs();
    cout << pairs << endl;
    return 0;
}