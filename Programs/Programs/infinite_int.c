#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char dig;
    struct NODE *post;
    struct NODE *pre;
}NODE;
typedef struct
{
    NODE *st,*lst;
}Integer;
Integer *init(void)
{
    Integer *i;
    i=(Integer*)malloc(sizeof(Integer));
    i->st=NULL;
    i->lst=NULL;
    return i;
}
void add_dig(Integer **no,int x)
{
    NODE *tmp;
    tmp=(NODE*)malloc(sizeof(NODE));
    tmp->dig=x+48;
    tmp->post=NULL;
    tmp->pre=NULL;
    if((*no)->st==NULL)
    {
        (*no)->st=tmp;
        (*no)->lst=tmp;
    }
    else
    {
        ((*no)->lst)->post=tmp;
        tmp->pre=(*no)->lst;
        (*no)->lst=tmp;
    }
}
void input(Integer **no)
{
    int tmp,i=0;
    char *str;
    //str=(char*)malloc(1);
    printf("\n Enter no : ");
    gets(str);
    strrev(str);
    while(str[i])
    {
        tmp=str[i]-48;
        add_dig(&(*no),tmp);
        i++;
    }
}
void display(Integer **i)
{
    NODE *tmp;
    tmp=(*i)->lst;
    while(tmp!=NULL)
    {
        printf("%c",tmp->dig);
        tmp=tmp->pre;
    }
}
Integer* add(Integer **no1,Integer **no2)
{
    Integer *tmp;
    NODE *tmp1,*tmp2;
    int carry=0,sum=0;
    tmp=init();
    tmp1=(*no1)->st;
    tmp2=(*no2)->st;
    while(tmp1||tmp2)
    {
        if(tmp1&&tmp2)
        {
            sum=((tmp1->dig)-48+(tmp2->dig)-48+carry)%10;
            carry=((tmp1->dig)-48+(tmp2->dig)-48+carry)/10;
            tmp1=tmp1->post;
            tmp2=tmp2->post;
        }
        else if(tmp1)
        {
            sum=((tmp1->dig)-48+carry)%10;
            carry=((tmp1->dig)-48+carry)/10;
            tmp1=tmp1->post;
        }
        else
        {
            sum=((tmp2->dig)-48+carry)%10;
            carry=((tmp2->dig)-48+carry)/10;
            tmp2=tmp2->post;
        }
        add_dig(&tmp,sum);
    }
    if(carry)
        add_dig(&tmp,carry);
    return tmp;
}
int main()
{
    Integer *no1,*no2,*no3;
    no1=init();
    no2=init();
    input(&no1);
    input(&no2);
    no3=add(&no1,&no2);
    printf("\n Sum is : ");
    display(&no3);
    return 0;
}
