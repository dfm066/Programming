#include "utils.h"
using namespace std;

#define MAX     100
#define LIMIT   1000000
#define BASE    1144066

long long fact(int n) {
    long long f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

long long nCr(int no) {
    long long N = 1;
    long long D = 1;
    int cnt = 0;
    int r = 0;
    for (r = 4; r <= no/2; r++) {
        N = no;
        int j = r;
        for (int i = 1; i < j; i++)  N *= (no-i);
        D = fact(r);
        if (N/D > LIMIT) break;
    }
    cnt = no - 2 * r + 1;
    return cnt;
}

int fast_solution() {
    double ratio = double(BASE)/LIMIT, exp = 1.0;
    double curr_ratio = 0.0, inv_ratio = 0.0;
    int curr_n = 24, curr_r = 10;
    int curr_n_r = 0, cnt = 4;
    for (;curr_n <= 100; curr_n++) {
        curr_n_r = curr_n - curr_r;
        ratio *= double(curr_n)/curr_n_r;
        while (ratio >= exp) {
            ++curr_n_r;
            curr_ratio = double(curr_r)/curr_n_r;
            inv_ratio = curr_n_r/double(curr_r);
            ratio *= curr_ratio;
            --curr_r;
        }
        ++curr_r;
        --curr_n_r;
        ratio *= inv_ratio;
        cnt += curr_n - 2*curr_r + 1;
    }
    return cnt;
}

int main()  {
    auto st = GET_HRTIME();
    
    long long gt_val = 0;
    long long curr_val = 0;
    for (int i = 23; i <= MAX; i++) {
        gt_val += nCr(i);
    }
    
    auto en = GET_HRTIME();
    time_diff exec_t = en-st;
    cout << " Solution : " << gt_val << endl;
    cout << "Time to execute : " << ms(exec_t).count() << "ms\t" 
       << us(exec_t).count() << "us\t" << ns(exec_t).count() << "ns\n" <<  endl;

    st = GET_HRTIME();

    gt_val = fast_solution();
    
    en = GET_HRTIME();
    cout << "Fast Solution : " << gt_val << endl;    
    exec_t = en-st;
    cout << "Time to execute : " << ms(exec_t).count() << "ms\t" 
       << us(exec_t).count() << "us\t" << ns(exec_t).count() << "ns\n" <<  endl;
       
    return 0;
}