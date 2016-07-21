#include<iostream>
#include<string.h>
using namespace std;
class Expression
{
	private: char s2[40];
		 char s1[40];
	
	public:
	void push(char ch,char tmp_stk[],int *tmp_top)
	{
		tmp_stk[++(*tmp_top)]=ch;
	}
	char pop(char tmp_stk[],int *tmp_top)
	{
		char tmp;
		tmp=tmp_stk[*tmp_top];
		tmp_stk[*tmp_top]='\0';
		(*tmp_top)--;
		return tmp;
	}

	void input()
	{
		cout<<"\nEnter Expression : ";
		cin>>s1;
	}
	void convToPost()
	{
		int i=0,top=-1,cnt=0,j=0,flg=0;
		char stk[40],tmp='\0';
		while(s1[i]!='\0')
		{
			if(s1[i]=='('||s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/'||s1[i]=='^')
			{
				if(s1[i]=='(')
				{
					flg=1;
					j++;
				}
				push(s1[i],stk,&top);
			}
			else if(s1[i]==')')
			{
				while(tmp!='(')
				{	
					tmp=pop(stk,&top);
					if(tmp!='(')
					{
						s2[cnt]=tmp;
						cnt++;
						s2[cnt]='\0';
					}
				}
				tmp='x';
				j--;
			}
			else if((s1[i]>='a'&&s1[i]<='z')||(s1[i]>='A'&&s1[i]<='Z'))
			{	
				s2[cnt]=s1[i];
				cnt++;
				s2[cnt]='\0';
			}
			i++;
		}
		while(tmp!='\0')
		{
			tmp=pop(stk,&top);
			s2[cnt]=tmp;
			cnt++;
		}
		s2[cnt]='\0';
		if(j!=0)
		{
			cout<<"\n "<<j<<"')' Expected";
		}
		
	}	
	void display()
	{
		cout<<"\nPre-fix expression is : "<<s1<<"\n Post-fix Expression is : "<<s2<<endl;
	}
};
int main()
{
	Expression e;
	e.input();
	e.convToPost();
	e.display();
	return 0;
}
