#include<iostream>
#include<string>
using namespace std;
int CountOccurrences(char ch,string s)
{
    int count=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]==ch) count++;
    }
    return count;
}
void RemoveOccurrences(char ch,string &s)
{
    int found=0 ;
    while((found = s.find(ch,found)) != string::npos)
        s.erase(found,1);
}
int main()
{
   string myString = "chihuahuas cheese crackers";
   RemoveOccurrences('c',myString);
   cout<<myString<<endl;

    return 0;
}
