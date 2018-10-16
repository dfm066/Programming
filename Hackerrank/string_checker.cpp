<<<<<<< HEAD
#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char **argv){
    ifstream in1(argv[1]);
    ifstream in2(argv[2]);
    char ch1,ch2;
    int cnt=0;
    while(!in1.eof()&&!in2.eof()){
        ch1= in1.get();
        ch2 = in2.get();
        cnt++;
        if(ch1!=ch2){
            cout<<ch1<<" "<<ch2<<" "<<cnt<<endl;
        }
    }
     in1.close();
    in2.close();
    return 0;
}
=======
#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char **argv){
    ifstream in1(argv[1]);
    ifstream in2(argv[2]);
    char ch1,ch2;
    int cnt=0;
    while(!in1.eof()&&!in2.eof()){
        ch1= in1.get();
        ch2 = in2.get();
        cnt++;
        if(ch1!=ch2){
            cout<<ch1<<" "<<ch2<<" "<<cnt<<endl;
        }
    }
     in1.close();
    in2.close();
    return 0;
}
>>>>>>> origin/master
