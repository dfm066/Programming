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
using namespace std;

int main(){
    int N;
    cin>>N;
    map<string,int> names;
    string tmp;
    fori(i,N){
        cin>>tmp;
        names[tmp]++;
    }
    string n1,n2;
    auto limit = prev(names.cend(), 1);
    int couple = 0;
    int c1,c2;
    for(auto i = names.cbegin(); i != limit; i++){
        n1 = (*i).first;
        n2 = (*(next(i,1))).first;
        c1 = (*i).second;
        c2 = (*(next(i,1))).second;
        if(n1.substr(0,n1.length()-1).compare(n2.substr(0,n2.length()-1))==0){
            c1 > c2 ? couple+=c2:couple+=c1;
        }
    }
    cout<<couple<<endl;
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
using namespace std;

int main(){
    int N;
    cin>>N;
    map<string,int> names;
    string tmp;
    fori(i,N){
        cin>>tmp;
        names[tmp]++;
    }
    string n1,n2;
    auto limit = prev(names.cend(), 1);
    int couple = 0;
    int c1,c2;
    for(auto i = names.cbegin(); i != limit; i++){
        n1 = (*i).first;
        n2 = (*(next(i,1))).first;
        c1 = (*i).second;
        c2 = (*(next(i,1))).second;
        if(n1.substr(0,n1.length()-1).compare(n2.substr(0,n2.length()-1))==0){
            c1 > c2 ? couple+=c2:couple+=c1;
        }
    }
    cout<<couple<<endl;
    return 0;
}
>>>>>>> origin/master
