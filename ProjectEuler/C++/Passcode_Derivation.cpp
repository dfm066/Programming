/*
Name : DFM066
Problem : 79

    A common security method used for online banking is to ask the user for three random
characters from a passcode. For example, if the passcode was 531278, they may ask for
the 2nd, 3rd, and 5th characters; the expected reply would be: 317.The text file, keylog.txt,
contains fifty successful login attempts. Given that the three characters are always asked for
in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.

*/

#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<fstream>

using namespace std;

int main(){
    ifstream keylog("keylog.txt");
    vector<string> keys;
    map<char,set<string>> first,second,third;
    set<char> master;
    string lines;
    while(!keylog.eof()){
        keylog>>lines;
        first[lines[0]].insert(lines);
        second[lines[1]].insert(lines);
        third[lines[2]].insert(lines);
        for(char ch:lines)
            master.insert(ch);
    }
    for(auto i:first){
        cout<<i.first<<":";
        for(auto j:first[i.first])
            cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(auto i:second){
        cout<<i.first<<":";
        for(auto j:second[i.first])
            cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(auto i:third){
        cout<<i.first<<":";
        for(auto j:third[i.first])
            cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(auto i:master)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}

// Answer : 73162890

