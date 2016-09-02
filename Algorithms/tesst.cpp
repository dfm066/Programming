#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define SIZE 1024
int m,n;
int fact(int x){
    int ans=1;
    for(int i=2;i<=x;i++){
        ans*=i;
    }
    return ans;
}

int check(char *str,int ans[]){
    int max=0,tot=0,cnt=0;
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++,tot=0){
            for(int k=0;k<n;k++){
                if(str[i*n+k]==1||str[j*n+k]==1){
                    tot++;
                }
            }
            if(tot>max){
                max=tot;
                ans[cnt]=max;
            }
        }
    }
    cout<<"\n All max score : ";
    for(int i=0;i<cnt;i++){
        cout<<"\n"<<ans[i];
    }
    return cnt;
}
int main(){

    cout<<"Enter values for m & n : ";
    cin>>m>>n;
    cout<<"\nPossible pairs : "<<(fact(m)/2);
    int *ans=new int(fact(m)/2);
    char *str=new char(m*n);
    //cout<<"\nSize of string : "<<sizeof(str);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>(str+i);
        }
    }
    ans = new int[fact(m)/fact(m-n)];
    int cnt=check(str,ans);

    return 0;

}
