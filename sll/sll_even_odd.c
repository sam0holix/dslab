#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *link;
}n;

n *head1=NULL,*head2=NULL,*head3=NULL;

n* create(n*);
void display(n*);
void even_odd(n*);

int main()
{
	printf("\ncreate 1st list: \n");
	head1=create(head1);
	printf("\nlist is : \n");
	display(head1);
	even_odd(head1);	
	return 0;
}
void display(n* head)
{
	n *ptr;
	ptr=head;
	if(head==NULL)
	{
		printf("\nlist doesnt exist.........\n");
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
n* create(n* head)
{
	n *ptr,*current;
	int ch;
	while(1)
	{
		ptr=(n*)malloc(sizeof(n));
		printf("\nenter the value..: ");
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
		printf("\ndo you want to continue?(1/0)..........");
		scanf("%d",&ch);
		if(ch!=1)
			break;
	}
	return head;
}
void even_odd(n* head)
{
	n *ptr,*ptr1,*current1,*current2;
	if(head==NULL)
	{
		printf("\nno list exist........");
	}
	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
			if(ptr->info%2==0)
			{
				ptr1=(n*)malloc(sizeof(n));
				ptr1->info=ptr->info;
				ptr1->link=NULL;
				if(head2==NULL)
				{	
					head2=ptr1;
					current1=ptr1;
				}
				else
				{
					current1->link=ptr1;
					current1=ptr1;
				}
			}
			else
			{
				ptr1=(n*)malloc(sizeof(n));
				ptr1->info=ptr->info;
				ptr1->link=NULL;
				if(head3==NULL)
				{	
					head3=ptr1;
					current2=ptr1;
				}
				else
				{
					current2->link=ptr1;
					current2=ptr1;
				}
			}
			ptr=ptr->link;
		}
	}
	printf("\neven list is:  \n");
	display(head2);
	printf("\nodd list is:  \n");
	display(head3);
}
