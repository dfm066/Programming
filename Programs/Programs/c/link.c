#include<stdio.h>
#include<stdlib.h>
struct student
{
    int marks;
    struct student *next;
};
struct student *start,*last,*tmp;
void add()
{
    tmp=(struct student*)malloc(sizeof(struct student));
    printf("\n Enter Marks : ");
    scanf("%d",&tmp->marks);
    tmp->next=NULL;
    if(start==NULL)
    {
	start=tmp;
	last=tmp;
    }
    else
    {
	last->next=tmp;
	last=tmp;
    }
}
void sort()
{
            int flg;
            struct student *st,*ls,*chg,*tmp2;
            st=start;
            while(st)
            {
                flg=1;
                chg=st;
                while(chg->marks<=st->marks)
                {
                    ls=st;
                    st=st->next;
                    if(st==NULL)
                    {
                        flg=0;
                        break;
                    }
                }
                if(flg)
                {
                    tmp=st->next;
                    ls->next=tmp;
                    st->next=chg;
                    if(ls==start)
                        start=st;
                    else
                        tmp2->next=st;
                }
                tmp2=chg;
                st=chg->next;
            }
}
void display()
{
    tmp=start;
    while(tmp)
    {
	printf("\n %d",tmp->marks);
	tmp=tmp->next;
    }
    getchar();
}
int main()
{
    int opt;
    while(1)
    {
        printf("\nMenu\n");
        printf("\n1.Add\n2.Sort\n3.Display\n4.Exit");
        printf("\n Choose the option : ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:add();
                        break;
            case 2:sort();
                        break;
            case 3:display();
                        break;
            case 4:exit(0);
        }
        system("cls");
    }
}
