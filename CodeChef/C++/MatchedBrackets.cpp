<<<<<<< HEAD
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#define fors(i,s) for(int i = 0; i < s.length(); i++)
#define fori(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define gc getchar
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int arr[100001];
int main(){
    int K;
    scanint(K);
    fori(i,K){
        scanint(arr[i]);
    }
    int depth=0,db=0,len=0,lb=0;
    int curr_depth=0,curr_len=0,curr_lb=0;
    for(int i = 0;i < K; i++){
        if(arr[i]==1){
            curr_depth++;
            curr_len++;
        }
        else{
            curr_depth--;
            curr_len++;

        }
        if(curr_depth>depth){
            depth = curr_depth;
            db = i+1;
        }
        if(curr_depth==0&&curr_len!=0){
            if(curr_len>len){
                len = curr_len;
                lb = i-len+2;

            }
            curr_len = 0;
        }
    }
    cout<<depth<<" "<<db<<" "<<len<<" "<<lb<<endl;

	return 0;
}
=======
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#define fors(i,s) for(int i = 0; i < s.length(); i++)
#define fori(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define gc getchar
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int arr[100001];
int main(){
    int K;
    scanint(K);
    fori(i,K){
        scanint(arr[i]);
    }
    int depth=0,db=0,len=0,lb=0;
    int curr_depth=0,curr_len=0,curr_lb=0;
    for(int i = 0;i < K; i++){
        if(arr[i]==1){
            curr_depth++;
            curr_len++;
        }
        else{
            curr_depth--;
            curr_len++;

        }
        if(curr_depth>depth){
            depth = curr_depth;
            db = i+1;
        }
        if(curr_depth==0&&curr_len!=0){
            if(curr_len>len){
                len = curr_len;
                lb = i-len+2;

            }
            curr_len = 0;
        }
    }
    cout<<depth<<" "<<db<<" "<<len<<" "<<lb<<endl;

	return 0;
}
>>>>>>> origin/master
