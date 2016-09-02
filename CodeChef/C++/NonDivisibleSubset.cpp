<<<<<<< HEAD
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sub[100];
int main() {
    int N,K;
    int tmp,sz;
    cin>>N>>K;
    for(int i = 0;i < N; i++){
        cin>>tmp;
        sub[tmp%K]++;
    }
    sz = 0;
    int limit = K/2;
    if( K%2==0){
        limit--;
        if(sub[K/2]>=1)
            sz++;
    }
    if(sub[0]>=1)
            sz++;

    for(int i = 1;i <= limit; i++){
        sz += sub[i]>sub[K-i]?sub[i]:sub[K-i];
    }
    if(sz==0)
        cout<<1<<endl;
    else
        cout<<sz<<endl;
    return 0;
}
=======
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sub[100];
int main() {
    int N,K;
    int tmp,sz;
    cin>>N>>K;
    for(int i = 0;i < N; i++){
        cin>>tmp;
        sub[tmp%K]++;
    }
    sz = 0;
    int limit = K/2;
    if( K%2==0){
        limit--;
        if(sub[K/2]>=1)
            sz++;
    }
    if(sub[0]>=1)
            sz++;

    for(int i = 1;i <= limit; i++){
        sz += sub[i]>sub[K-i]?sub[i]:sub[K-i];
    }
    if(sz==0)
        cout<<1<<endl;
    else
        cout<<sz<<endl;
    return 0;
}
>>>>>>> origin/master
