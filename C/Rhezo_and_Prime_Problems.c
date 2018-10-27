#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int arr[5000];
int sarr[5000];
bool isPrime(int num){
    int limit = (int)sqrt(num)+1;
    if(num<2)
        return false;
    for(int i = 2; i < limit; i++){
        if(num%i==0)
            return false;
    }
    return true;
}
int main()
{
    int N;
    int sum = 0;
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d",&arr[i]);
        sum += arr[i];
        sarr[i] = sum;
    }
    int max_len1 = N%2==0?N-1:N;
    while(!isPrime(max_len1)&&max_len1 > 0){
        max_len1 -= 2;
    }
    int max_len2;
    int tmp_sum1,tmp_sum2,tmp_sum;
    int sum2;
    sum = 0;
    if(isPrime(max_len1)){
        tmp_sum1 = 0;
        tmp_sum2 = 0;
        for(int i = 0,j = i+max_len1-1; j < N;i++,j++){
            tmp_sum1 = sarr[j]-sarr[i] + arr[i];
            max_len2 = N-j-2;
            while(!isPrime(max_len2)&&max_len2>0){
                max_len2 -= 1;
            }
            if(isPrime(max_len2)){
                for(int k = j+1, l = k+max_len2; l < N; k++,l++){
                    sum2 = sarr[l+max_len2]-sarr[k+1]+arr[l+1];
                    if(tmp_sum2<sum2)
                        tmp_sum2 = sum2;
                }

            }
            tmp_sum = tmp_sum1+tmp_sum2;
            if(tmp_sum > sum)
                sum = tmp_sum;
        }
        printf("\n%d %d %d %d",max_len1,max_len2,tmp_sum1,tmp_sum2);
    }
    printf("\n%d",sum);
    return 0;
}
