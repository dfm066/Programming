#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n;
    arr[0]=0;arr[1]=2;arr[2]=1;arr[3]=1;arr[4]=1;arr[5]=1;
    for(int i = 6; i <= 100; i++){
      if((arr[i-5]==2)||(arr[i-3]==2)||(arr[i-2]==2))
        arr[i]=1;
      else
        arr[i]=2;
    }
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        if(arr[n]==1)
          printf("First\n");
        else
          printf("Second\n");
    }

    return 0;
}
