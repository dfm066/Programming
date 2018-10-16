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
#define ll long long
using namespace std;
ll arr[100001];
int main(){
    int N,com,ptr,st;
    ll H;

    scanf("%d %lld",&N,&H);
    fori(i,N){
        scanf("%lld",&arr[i]);
    }
    ptr = 0;
    st = 0;
    while(1){
        scanf("%d",&com);
        if(com==0)
            break;
        switch(com){
        case 1:if(ptr>0)
                ptr--;
                break;
        case 2:if(ptr<N-1)
                ptr++;
            break;
        case 3:if(st==0&&arr[ptr]){
                    st = 1;
                    arr[ptr]--;
                }
            break;
        case 4:if(st==1&&arr[ptr]<H){
                    st = 0;
                    arr[ptr]++;
                }
            break;
        }
    }
    fori(i,N){
        printf("%lld ",arr[i]);
    }
    cout<<endl;
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
#define ll long long
using namespace std;
ll arr[100001];
int main(){
    int N,com,ptr,st;
    ll H;

    scanf("%d %lld",&N,&H);
    fori(i,N){
        scanf("%lld",&arr[i]);
    }
    ptr = 0;
    st = 0;
    while(1){
        scanf("%d",&com);
        if(com==0)
            break;
        switch(com){
        case 1:if(ptr>0)
                ptr--;
                break;
        case 2:if(ptr<N-1)
                ptr++;
            break;
        case 3:if(st==0&&arr[ptr]){
                    st = 1;
                    arr[ptr]--;
                }
            break;
        case 4:if(st==1&&arr[ptr]<H){
                    st = 0;
                    arr[ptr]++;
                }
            break;
        }
    }
    fori(i,N){
        printf("%lld ",arr[i]);
    }
    cout<<endl;
    return 0;
}
>>>>>>> origin/master
