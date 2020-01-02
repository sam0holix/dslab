#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *link;
}n;

n *last1=NULL,*last2=NULL;

n* create(n*);
void display(n*);
void concate(n*,n*);

int main()
{
	printf("\ncreate 1st list: \n");
	last1=create(last1);
	printf("\ncreate 2nd list: \n");
	last2=create(last2);
	printf("\nlists are  : \n");
	display(last1);
	printf("\n");
	display(last2);
	concate(last1,last2);	
	return 0;
}
void display(n* last)
{
	n *ptr;
	if(last==NULL)
	{
		printf("\nno list exist.......");
		return;
    }
	ptr=last->link;
	while(ptr!=last)	
	{
		printf("%d\t",ptr->info);
		ptr=ptr->link;
	}
	printf("%d\t",last->info);
}
n* create(n* last)
{
	n *ptr;
	int ch;
	while(1)
	{
		ptr=(n*)malloc(sizeof(n));
		printf("\nenter the value : ");
		scanf("%d",&ptr->info);
		ptr->link=ptr;
		if(last==NULL)
		{
			last=ptr;
		}
		else
		{
			ptr->link=last->link;
			last->link=ptr;
			last=ptr;
		}
		printf("\ndo you want to continue?(1/0)......");
		scanf("%d",&ch);
		if(ch!=1)
			break;
	}
	return last;
}
void concate(n* last1,n* last2)
{
	n *x;
	x=last2->link;
	last2->link=last1->link;
	last1->link=x;
	printf("\nfinal list is :  \n");
	display(last2);	
}
