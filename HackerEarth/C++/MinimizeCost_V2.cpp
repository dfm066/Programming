#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<math.h>

int min(int a, int b) {
    return a > b ? b : a;
}  

long long Solve (int n, long long k, int* arr ) {
     for (int positive = 0, negative = 0; positive < n; positive++) {
        if (arr[positive] <= 0) {
            continue;
        }
        
        while (positive - negative > k) negative++;
       
        while(arr[positive] != 0 && (positive + k >= min(n-1, negative))) {
            if (arr[negative] >= 0) {
                negative++;
                continue;
            }
            int transfer = min(arr[positive], abs(arr[negative]));
            arr[positive] -= transfer;
            arr[negative] += transfer;
            if (arr[negative] == 0) negative++; 
        }
    }

    long long res = 0;
    for (int i = 0; i < n; i++)  {
        res += abs(arr[i]);
    }
    return res;
}

int main() {
    long long k;
    
    int n;
    scanf("%d", &n);
    scanf("%lld", &k);
    int i_arr;
    int *arr = (int *)malloc(n * sizeof(int));
    for(i_arr=0; i_arr<n; i_arr++) {
    	scanf("%d", &arr[i_arr]);  
    }

    long long out_ = Solve(n, k, arr);
    printf("%lld", out_);
}