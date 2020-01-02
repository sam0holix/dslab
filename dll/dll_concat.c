#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	int info;
	struct node *llink,*rlink;
}n;

n* create_node()
{
	n *ptr;
	ptr=(n*)malloc(sizeof(n));
	ptr->llink=NULL;
	ptr->rlink=NULL;
	return ptr;
}

void display(n *head)
{
	n *ptr;
	if(head==NULL)
	{
		printf("\nno list exist........");
	}
	else
	{
		printf("\n");
		ptr=head;
		while(ptr!=NULL)
		{ 
			printf("%d\t",ptr->info);
			ptr=ptr->rlink;
		}
	}
}
n* create_list(n *head)
{
	n *ptr,*current;
	int ch,val;
	while(1)
	{
		printf("\nenter the value: ");
		scanf("%d",&val);
		ptr=create_node();
		ptr->info=val;
		if(head==NULL)
		{
			head=ptr;
			current=ptr;
			printf("\ninsertion successfull......");
		}
		else
		{
			current->rlink=ptr;
			ptr->llink=current;
			current=ptr;
			printf("\ninsertion successfull......");
		}
		printf("\ndo you want to continue?(1/0)....");
		scanf("%d",&ch);
		if(ch!=1)
			break;
	}
	return head;
}
n* concate(n *head,n *head1)
{
	n *x;
	x=head;
	while(x->rlink!=NULL)
		x=x->rlink;
	x->rlink=head1;
	head1->llink=x;
	return head;
}
int main()
{
	n *ptr,*head=NULL,*head1=NULL;
	int ch,val;
	printf("\ncreate 1st list........\n");
	head=create_list(head);
	printf("\ncreate 2nd list........\n");
	head1=create_list(head1);
	printf("\n1st list is: \n");
	display(head);
	printf("\n2nd list is: \n");
	display(head1);
	printf("\nfinal list is : \n");
	head=concate(head,head1);
	display(head);
	return 0;
}
