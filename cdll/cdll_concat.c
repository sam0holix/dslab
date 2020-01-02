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
	ptr->llink=ptr;
	ptr->rlink=ptr;
	return ptr;
}

void display(n *last)
{
	n *ptr;
	if(last==NULL)
	{
		printf("\nno list exist........");
	}
	else
	{
		printf("\n");
		ptr=last->rlink;
		while(ptr!=last)
		{
			printf("%d\t",ptr->info);
			ptr=ptr->rlink;
		}
		printf("%d\t",last->info);
	}
}
n* insert_end(n *last,int val)
{
	n *ptr,*x;
	ptr=create_node();
	ptr->info=val;
	if(last==NULL)
	{
		last=ptr;
		printf("\ninsertion successfull......");
	}
	else
	{
		x=last->rlink;
		ptr->rlink=x;
		x->llink=ptr;
		last->rlink=ptr;
		ptr->llink=last;
		last=ptr;
		printf("\ninsertion successfull......");
	}
	return last;
}
n* concate(n *last,n *last1)
{
	n *x;
	x=last1->rlink;
	last1->rlink=last->rlink;
	last1->rlink->llink=last1;
	last->rlink=x;
	x->llink=last;
	return last1;
}
int main()
{
	n *ptr,*last=NULL,*last1=NULL;
	int ch,val;
	printf("\ncreate 1st list........\n");
	while(1)
	{
		ptr=create_node();
		printf("\nenter your value: ");
		scanf("%d",&val);
		last=insert_end(last,val);
		printf("\nenter your choice?(1/0)........");
		scanf("%d",&ch);
		if(ch!=1)
			break;
	}
	printf("\ncreate 2nd list........\n");
	while(1)
	{
		ptr=create_node();
		printf("\nenter your value: ");
		scanf("%d",&val);
		last1=insert_end(last1,val);
		printf("\nenter your choice?(1/0)........");
		scanf("%d",&ch);
		if(ch!=1)
			break;
	}	
	printf("\n1st list is: \n");
	display(last);
	printf("\n2nd list is: \n");
	display(last1);
	printf("\nfinal list is : \n");
	last1=concate(last,last1);
	display(last1);
	return 0;
}
