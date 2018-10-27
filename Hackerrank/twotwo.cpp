#include <bits/stdc++.h>
#define MAX_POW 800
using namespace std;

int main(){
        int val,carry = 0;
        vector<int> power;
        array<int, 14> digits;
        vector<array<int, 14>> trie;
        int pos,parent,child,suffix,dict_suffix;
        power.push_back(1);
        digits.fill(0);
        digits[1] = 1;
        digits[11] = digits [12] = digits[13] = 0;
        trie.push_back(digits);
        digits.fill(0);
        digits[10] = 1;
        trie.push_back(digits);
        /* Building Trie for powers of 2*/
        for(int i = 1; i <= MAX_POW; i++){
            carry = 0;
            digits.fill(0);
            for(int j = 0; j < power.size(); j++){
                val = power[j] * 2 + carry;
                carry = val / 10;
                power[j] = val % 10;
            }
            if(carry > 0)
                power.push_back(carry);
            pos = 0;
            for(auto j = power.crbegin(); j != power.crend(); j++){
                if(trie[pos][*j] != 0){
                    parent = pos;
                    pos = trie[pos][*j];
                    trie[pos][11] = parent;

                }
                else{
                    parent = pos;
                    trie[pos][*j] = trie.size();
                    pos = trie.size();
                    digits.fill(0);
                    if(j == prev(power.crend()))
                        digits[10] = 1;
                    trie.push_back(digits);
                    trie[pos][11] = parent;
                }
            }
        }
        /* Building Suffix links by AC*/
        queue<int> q;
        for(int i = 0; i < 10; i++){
            if(trie[0][i] != 0){
                child = trie[0][i];
                q.push(child);
            }
        }

        while(!q.empty()){
            parent = q.front();
            q.pop();
            for(int i =0; i < 10; i++){
                if(trie[parent][i] != 0){
                    child = trie[parent][i];
                    suffix = trie[parent][12];
                    while(suffix != 0 && trie[suffix][i] == 0){
                        suffix = trie[suffix][12];
                    }
                    if(trie[suffix][i]!=0)
                        trie[child][12] = trie[suffix][i];
                    else
                        trie[child][12] = suffix;
                    q.push(child);
                }
            }
        }
        /* Building Dictionary Suffix by AC */
        for(int i = 0; i < 10; i++){
            if(trie[0][i] != 0){
                child = trie[0][i];
                trie[child][13] = 0;
                q.push(child);
            }
        }
        while(!q.empty()){
            parent = q.front();
            q.pop();
            for(int i =0; i < 10; i++){
                if(trie[parent][i] != 0){
                    child = trie[parent][i];
                    suffix = trie[child][12];
                    while(suffix != 0 && trie[suffix][10] != 1 ){
                        suffix = trie[suffix][12];
                    }
                    if(trie[suffix][10] == 1)
                        trie[child][13] = suffix;
                    else
                        trie[child][13] = 0;
                    q.push(child);
                }
            }
        }
        /* test driver */
        int tc,cnt,i,next;
        string  no;
        cin >> tc;
        while(tc--){
            cin >> no;
            cnt = 0;
            parent = 0;
            for(i = 0;i < no.length(); i++){
                    child = trie[parent][no[i]-'0'];
                    if(parent == 0 && child == 0)
                        continue;
                    if(child == 0){
                       parent = trie[parent][12];
                       i--;
                       continue;
                    }
                    if(trie[child][10] == 1)
                        cnt++;
                    dict_suffix = trie[child][13];
                    while(dict_suffix != 0){
                        cnt ++;
                        dict_suffix = trie[dict_suffix][13];
                    }
                    parent = child;
            }
            cout << cnt << endl;
        }
        return 0;
}
