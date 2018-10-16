<<<<<<< HEAD
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,D,tmp;
    cin>>N>>D;
   vector<int> shares;
    bool flag=false;
    int min=0,st=0,en=0;

    for(int i = 0; i < N; i++){
        cin>>tmp;
        shares.push_back(tmp);
    }

    while(D--){

        cin>>tmp;
        flag=false;

        for(min = 1; min < N && !flag; min++){
            for(st = 0,en = st+min; en < N; st++,en++){
                if(shares[en]-shares[st]==tmp){
                    flag=true;
                    break;
                }
            }
        }
        if(flag == false)
            cout<<"-1"<<endl;
        else
            cout<<st+1<<" "<<en+1<<endl;
    }
    return 0;
}

=======
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,D,tmp;
    cin>>N>>D;
   vector<int> shares;
    bool flag=false;
    int min=0,st=0,en=0;

    for(int i = 0; i < N; i++){
        cin>>tmp;
        shares.push_back(tmp);
    }

    while(D--){

        cin>>tmp;
        flag=false;

        for(min = 1; min < N && !flag; min++){
            for(st = 0,en = st+min; en < N; st++,en++){
                if(shares[en]-shares[st]==tmp){
                    flag=true;
                    break;
                }
            }
        }
        if(flag == false)
            cout<<"-1"<<endl;
        else
            cout<<st+1<<" "<<en+1<<endl;
    }
    return 0;
}

>>>>>>> origin/master
