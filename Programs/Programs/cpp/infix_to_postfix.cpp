#include<string.h>
#include<iostream>
using namespace std;
int nc=-1;
class expression
{
private:
    char stck[40],tmp,str[40],postfixexpr[40],toptkn;
    int i,j;
public:
void getexpr()
        {
            cin>>str;
        }
int priority(char token)
{
    if(token=='(')
        return 0;
    else if(token=='+'||token=='-')
        return 1;
    else if(token=='*'||token=='/')
        return 2;
    else
        return 3;
}
int emptystack()
{
    if(stck[nc]=='\0')
        return 1;
    else
        return 0;
}
int isoperator(char data)
{
    if(data=='+'||data=='-'||data=='*'||data=='/'||data=='^')
        return 1;
    else
        return 0;
}
void push(char data)
{
    stck[++nc]=data;
}
char stacktop()
{
    return stck[nc];
}
char pop()
{
    return stck[nc--];
}
void convert()
{
    int i=0;
    int j=0;
    while(str[i]!='\0')
    {
        if(str[i]=='(')
            push(str[i]);
        else if(str[i]==')')
        {
            toptkn=pop();
            while(toptkn!='(')
                    {
                        postfixexpr[j++]=toptkn;
                        toptkn=pop();
                    }
        }
        else if(isoperator(str[i]))
        {
            if(!emptystack())
            {
                toptkn=stacktop();
                while(!emptystack()&&priority(str[i])<=priority(toptkn))
                {
                    tmp=pop();
                   // printf("\n\n%c\n\n%c",toptkn,str[i]);
                    postfixexpr[j++]=tmp;
                   // printf("\n%s",postfixexpr);
                   if(!emptystack())
                   toptkn=stacktop();
                }
            }
            push(str[i]);
        }
        else
                postfixexpr[j++]=str[i];
        i++;
    }
    while(!emptystack())
    {
        toptkn=pop();
        postfixexpr[j++]=toptkn;
    }
        postfixexpr[j++]='\0';

}
void putexpr()
{
    cout<<postfixexpr;
}
};
int main()
{
    expression e;
    e.getexpr();
    e.convert();
    e.putexpr();
    return 0;
}
