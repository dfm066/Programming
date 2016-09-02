#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<float.h>

typedef struct student{
    int roll_no;
    float percent;
    struct student *next;
}student;

int main(){
    int opt=0;
    bool flag=true;
    student *start=NULL,*node,*tmp,*last;
    while(flag){
        printf("\nMenu:\n1.Create student\n2.Show info\n3.Stop\n");
        scanf("%d",&opt);
        switch(opt){
            case 1:node=(student*)malloc(sizeof(student));
                    printf("\nEnter Roll No : ");
                    scanf("%d",&node->roll_no);
                    printf("\nEnter Roll No : ");
                    scanf("%f",&node->percent);
                    node->next=NULL;
                    if(start==NULL){
                        start=node;
                        last=node;
                    }
                    else{
                        last->next=node;
                        last=node;
                    }
                     printf("\n Student info inserted..");
                    break;
            case 2:tmp=start;
                    printf("\nRoll No\tPercentage\n");
                    while(tmp!=NULL){
                        printf("\n%5d\t  %0.2f",tmp->roll_no,tmp->percent);
                        tmp=tmp->next;
                    }
                    break;
            case 3:printf("\nThank you for using our service.");
                    flag=false;
        }
    }
    return 0;
}
