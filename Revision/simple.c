#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main()
{
	STACK std;
	NODE *tmp=NULL;
	int opt=1;
	init(&std);
	while(opt){
		printf("\n\nPress 1 to Push\nPress 2 for displaying stack top\nPress 3 to Pop\nPress 4 to display stack\nPress 0 to Stop\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				tmp=(NODE*)malloc(sizeof(NODE));
				tmp->data=(int*)malloc(sizeof(int));
				printf("\nEnter data : ");
				scanf("%d",(int*)tmp->data);
				tmp->next=NULL;
				push(tmp,&std);
				break;
			case 2:
				*tmp=stackTop(std);
				printf("\nStack Top =  %d",*(int*)tmp->data);	
				break;
			case 3:
				if(std.top!=null)
					*tmp=pop(&std);
				if(tmp!=NULL)
					printf("\n%d is Poped.",*(int*)tmp->data);
				else
					printf("\nEmpty Stack");
				free(tmp);
				break;
			case 4:
				printf("\nStack :");
				display(std);
				break;
			default:
				printf("\nExiting...");
		}	
		
	}
	return 0;
}
