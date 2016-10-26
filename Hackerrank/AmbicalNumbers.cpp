#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LIMIT 100000
int sum[LIMIT+1];
int ambical_sum[LIMIT+1];
bool flg[LIMIT+1];

int factor_sum(int no){
    if(no <= 1)
        return 0;
    int sum = 1;
    int bound = (int)sqrt(no);
    if(bound*bound == no)
        sum+= bound;
    for(int i = 2; i < bound; i++){
        if( no % i == 0){
            sum += i + no /i;
        }
    }
    return sum;
}
void build_sum(){
   int f_sum = 0;
   for(int i = 0; i <= LIMIT; i++){
        f_sum = factor_sum(i);
        if(i != f_sum && i == factor_sum(f_sum)){
            flg[i] = true;
            if(f_sum <= LIMIT)
                flg[f_sum] = true;
        }
        else
            flg[i] = false;
   }
   int curr = 0;
   for(int i = 0; i <= LIMIT; i++){
        ambical_sum[i] = curr;
        if(flg[i] == true)
            curr += i;
   }
   return;
}
int main() {
    build_sum();
    int t,n;
    cin >> t;

    while(t--){
        cin >> n;
        cout << ambical_sum[n] << endl;
    }
    return 0;
}
