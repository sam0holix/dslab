#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *link;	
}n;
n *head=NULL;
void display(n*);
n* right_high_del(n*);

int main()
{
	n *ptr,*current;
	int ch;
	while(1)
	{
		ptr=(n*)malloc(sizeof(n));
		printf("\nenter the value: ");
		scanf("%d",&ptr->info);
		ptr->link=NULL;
		if(head==NULL)
		{
			head=ptr;
			current=ptr;
		}
		else
		{
			current->link=ptr;
			current=ptr;
		}
		printf("\ndo you want to continue?..(0/1)...");
		scanf("%d",&ch);
		if(ch!=1)
			break;
	}	
	display(head);
	head=right_high_del(head);
	printf("\nfinal list is.....\n");
	display(head);
	return 0;
}
void display(n* head)
{
	n *ptr;
	ptr=head;
	if(head==NULL)
	{
		printf("\nnolist exist......");
	}
	else
	{
		printf("\n");
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->info);
			ptr=ptr->link;
		}
	}
}
n* right_high_del(n* head)
{
	n *ptr,*x,*y;
	int flag=1;
	while(1)
	{
		flag=1;
		ptr=head;
		x=ptr->link;
		if(ptr->info<x->info)
		{
			ptr=ptr->link;
			head=ptr;
			flag=0;		
		}	
		else
		{
			while(x!=NULL)
			{
				y=x;
				x=x->link;
				if(x!=NULL && y->info<x->info)
				{
					ptr->link=y->link;
					flag=0;
				}
				ptr=ptr->link;
			}				
		}
		display(head);
		if(flag==1)
			break;
	}
	return head;
}
