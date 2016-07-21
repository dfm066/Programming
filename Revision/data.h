#include<stdio.h>

typedef struct NODE
{

	void *data;
	struct NODE *next;
}NODE;
typedef struct STACK
{
	NODE *top;
	int cnt;
}STACK;
void init(STACK *tmp)
{
	tmp->top=NULL;
	tmp->cnt =0;
}

int push(NODE *in,STACK *curr)
{

	in->next=curr->top;
	curr->top=in;
	curr->cnt++;
	return 1;
}

NODE pop(STACK *curr)
{
	NODE *tmp=NULL;
	tmp=curr->top;
	curr->top=tmp->next;	
	return *tmp;
}

NODE stackTop(STACK curr)
{
	NODE *tmp;
	tmp=curr.top;
	return *tmp;
}
void display(STACK tmp)
{
	NODE n;
	while(tmp.top!=NULL)
	{
		n=*tmp.top;
		tmp.top=n.next;
		tmp.cnt--;
		printf("%d\n",*(int*)n.data);
	}


}


