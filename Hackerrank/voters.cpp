#include <iostream>
#include<map>
#include<vector>
using namespace std;

string winner(vector<string> votes){
        string win= "";
        unsigned int max=0;
        map<string,unsigned int> m;
        for(auto v : votes){
                m[v]++;
        }
        for(auto i : m){
            if(i.second >= max && i.first!=""){
                    max = i.second;
                    win = i.first;
                }
        }
        return win;
}

int main(int argc, char **argv)
{
	int voters;
    string tmp;
    cin >> voters;
    vector<string> votes(voters);
    for(int i = 0; i < voters; i++){
        cin>>tmp;
        votes.push_back(tmp);
    }

    cout << winner(votes);
	return 0;
}
