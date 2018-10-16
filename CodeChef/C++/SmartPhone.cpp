<<<<<<< HEAD
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#define fors(i,s) for(int i = 0; i < s.length(); i++)
#define fori(i,n) for(int i = 0; i < n; i++)
#define ull unsigned long long

using namespace std;
ull arr[500001];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){
    int N;
    scanf("%d",&N);
    fori(i,N){
        scanf("%ulld",&arr[i]);
    }
    qsort(arr, N, sizeof(ull), compare);
    ull profit,tmp;
    profit = 0;
    for(int i = N-1;i >= 0; i--){
        tmp = arr[i]*(N-i);
        if(tmp>profit){
            profit = tmp;
        }
    }
    printf("%lld\n",profit);
	return 0;
}
=======
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#define fors(i,s) for(int i = 0; i < s.length(); i++)
#define fori(i,n) for(int i = 0; i < n; i++)
#define ull unsigned long long

using namespace std;
ull arr[500001];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){
    int N;
    scanf("%d",&N);
    fori(i,N){
        scanf("%ulld",&arr[i]);
    }
    qsort(arr, N, sizeof(ull), compare);
    ull profit,tmp;
    profit = 0;
    for(int i = N-1;i >= 0; i--){
        tmp = arr[i]*(N-i);
        if(tmp>profit){
            profit = tmp;
        }
    }
    printf("%lld\n",profit);
	return 0;
}
>>>>>>> origin/master
