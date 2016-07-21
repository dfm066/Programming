
#include<iostream>
using namespace std;
#include<string.h>
class String
{
    protected:
        char a[100];
    public:
        String()
        {
            char str[1000]="\0";
            strcpy(a,str);
        }
        String(char str[])
        {
            strcpy(a,str);
        }

        String(String &st)
        {
            strcpy(a,st.a);
        }
        void display()
        {
            cout<<"\nstring="<<a;
        }
};

int main()
{
    String s1;
    s1.display();
    String s2("abc");
    s2.display();
    String s3(s2);
    s3.display();
}
