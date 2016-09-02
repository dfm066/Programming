#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
class Brute
{
    char *str;
    int len,lim;
    long cnt;
public:
    void getData();
    void init();
    void print(int);
    void printCount();
    void attack();
    ~Brute()
    {
        delete[](str);
    }
};
void Brute::getData()
{
    cout<<"Enter Length : ";
    cin>>len;
    cout<<"Enter Character limit :";
    cin>>lim;
}
void Brute::printCount()
{
    cout<<endl<<"Count: "<<cnt;
    free(str);
}
void Brute::init()
{
    int i;
    cnt=0;
    str=new char[len+1];
    for(i=0;i<len;i++)
        *(str+i)=48;
    *(str+i)='\0';
}
void Brute::print(int curr)
{
        if(curr==-1)
        {
            cnt++;
            cout<<" "<<str;
            return;
        }
        else
        {
            (*(str+curr))++;
            if((*(str+curr))>(lim+48))
            {
                *(str+curr)=48;
                print(curr-1);
                return;
            }
            cnt++;
            cout<<" "<<str;
            print(len-1);
        }
        return;
}
void Brute::attack()
{
    print(len-1);
    cout<<"\t count : "<<cnt;
}
int main()
{
    Brute fc;
    fc.getData();
    fc.init();
    fc.attack();
    fc.printCount();
    return 0;
}
