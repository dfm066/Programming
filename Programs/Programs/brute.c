#include<iostream>
#include<stdlib>
#include<string>
#include<math>
class Brute
{
    char *str;
    int len,lim;
    long cnt;
public:
    void getData();
    void init();
    int print(int);
    void calCount();
};
void Brute::getData()
{
    cout<<"Enter Length : ";
    cin>>len;
    cout<<"Enter Character limit :";
    cin>>lim;
}
void Brute::calCount()
{
    cnt=pow(len,lim+1);
}
void Brute::init()
{
    str=new char[len+1];
    for(int i=0;i<len;i++)
        *(str+i)=48;
    *(str+i)='\0';
}
int Brute:print(int curr)
{
        if(curr==-1)
        {
            cout<<str;
            return 1;
        }
        else
        {
            (*(str+curr))++;
            if((*(str+curr))>(lim+48))
            {
                *(str+curr)=48;
                if(print(curr-1))
                    return 1;
            }
            cout<<str;
            if(print(len-1))
                return 1;
            return 0;
        }

}
int main()
{

}
