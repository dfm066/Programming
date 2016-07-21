#include <iostream>
#include <string>
using namespace std;
void censorString(string &in,string censor)
{
    int pos;
    for(int i=0; i<censor.length(); i++)
    {
            while((pos=in.find((char)censor[i])) != string::npos)
                in.erase(pos,1);
    }

}
int main()
{
    string in="Stanford University";
    string censor="nt";

    cout<<"\nEnter main string : ";
    getline(cin,in);
    cout<<"\nEnter censor string : ";
    getline(cin,censor);

    censorString(in,censor);
    cout<<"\nCensored string : "<<in;
}
