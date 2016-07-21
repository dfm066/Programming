#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#define LIM 10e4
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int ar[100001];
    int T,N,max;
    int curr_sum,cont_sum,noncont_sum;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;
        cont_sum = max = -LIM;
        curr_sum = 0;
        noncont_sum = 0;
        for(int j =0; j < N; j++){
            cin >> ar[j];
            curr_sum+=ar[j];
            if(curr_sum<0)
                curr_sum = 0;
            if(curr_sum>cont_sum)
                cont_sum=curr_sum;
            if(ar[j]>0)
                noncont_sum+=ar[j];
            if(ar[j]>max)
                max=ar[j];
        }
        if(cont_sum==0){
            cont_sum=noncont_sum=max;
        }
        cout<<cont_sum<<" "<<noncont_sum<<endl;
    }
    return 0;
}
