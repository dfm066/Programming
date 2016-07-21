#include <iostream>
#include <fstream>
using namespace std;
int isChar(char ch)
{
    if(ch>='A'&&ch<='Z')
        return 1;
    else if(ch>='a'&&ch<='z')
        return 2;
    else return 0;
}
int main()
{
    ifstream in;
    ofstream out;
    char ch='.';
    int freq[26]={0};
    int max=0;
    in.open("in.txt");
    out.open("out.txt");
    if(in.fail())
    {
        cout<<"\nFail to open in.txt";
        in.clear();
        return 0;
    }
    if(out.fail())
    {
        cout<<"\nFail to create out.txt";
        out.clear();
        return 0;
    }
    while(ch!= EOF)
    {
        ch=in.get();
        switch(isChar(ch))
        {
            case 0:break;
            case 1:freq[ch-65]++;
                break;
            case 2:freq[ch-97]++;
                break;
        }
    }
    for(int i=0; i<26; i++)
    {
            if(max<freq[i])
                max=freq[i];
    }
    for(int i=0; i<max; i++)
    {
        for(int j=0; j<26; j++)
        {
            if(max-i<=freq[j])
                out.put('*');
            else out.put(' ');
            out.put(' ');
        }
        out.put('\n');
    }
    for(int i=0; i<26; i++)
    {
        out.put(char(65+i));
        out.put(' ');
    }
    in.close();
    out.close();
    return 0;
}
