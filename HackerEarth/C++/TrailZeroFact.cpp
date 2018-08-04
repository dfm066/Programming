#include <bits/stdc++.h>
using namespace std;

#define MAX 100001
int convo_table[MAX];

void build_convo_table() {
    int cnt = 0;
    int num = 0;
    int curr_pow = 0;
    int factor = 0;

    do {
        convo_table[cnt] = num;
        num += 5;
        curr_pow = 0;
        factor = 5;
        while(num % factor == 0) {
            curr_pow++;
            factor *= 5;
        }
        cnt += curr_pow;
        
    } while (cnt < MAX);
    return;
}

int main () {
    int T, M, start;
    memset(convo_table, -1, sizeof(int)*(MAX));
    build_convo_table();
    cin >> T;
    while(T--){
        cin >> M;
        start = convo_table[M];
        if (start == -1)  cout << 0 << endl;
        else {
            cout << 5 << endl;
            for (int i = start; i < start+5; i++)   cout << i << " ";
            cout << endl;
        }

    }
    return 0;

}