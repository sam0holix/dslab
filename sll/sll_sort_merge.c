#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *link;
}n;

n *head1=NULL,*head2=NULL;

n* create(n*);
void display(n*);
void sort_merge();

int main()
{
	printf("\ncreate 1st list: \n");
	head1=create(head1);
	printf("\ncreate 2nd list: \n");
	head2=create(head2);
	printf("\n1st list is: \n");
	display(head1);
	printf("\n2nd list is: \n");
	display(head2);
	sort_merge();
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
void sort_merge()
{
	n *ptr1,*ptr2,*ptr3,*ptr,*current,*head=NULL;
	ptr1=head1;
	ptr2=head2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		ptr=(n*)malloc(sizeof(n));
		ptr->link=NULL;
		if(ptr1->info<ptr2->info)
		{
			ptr->info=ptr1->info;
			ptr1=ptr1->link;
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
		}
		else if(ptr1->info>ptr2->info)
		{
			ptr->info=ptr2->info;
			ptr2=ptr2->link;
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
		}
		else
		{
			ptr->info=ptr1->info;
			ptr1=ptr1->link;
			ptr2=ptr2->link;
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
		}
	}	
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			ptr=(n*)malloc(sizeof(n));
		    ptr->link=NULL;
			ptr->info=ptr2->info;
			ptr2=ptr2->link;
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
		}
	}
	if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			ptr=(n*)malloc(sizeof(n));
		    ptr->link=NULL;
			ptr->info=ptr1->info;
			ptr1=ptr1->link;
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
		}
	}
	if(head==NULL)
	{
		printf("\nno list exist.....");
	}
	else
	{
		ptr3=head;
		printf("\nfinal list is.....\n");
		while(ptr3!=NULL)
		{
			printf("%d\t",ptr3->info);
			ptr3=ptr3->link;
		}
	}
}
