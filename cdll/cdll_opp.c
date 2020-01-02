#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
	int info;
	struct node *llink,*rlink;
}n;


n *last=NULL;

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

n* insert_front(n *last,int val)
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
		printf("\ninsertion successfull......");
	}
	return last;
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

n* delete_end(n *last)
{
	n *x;
	if(last==NULL)
	{
		printf("\nno list exist........");
	}
	else if(last->rlink==last)
	{
		free(last);
		last=NULL;
		printf("\ndeletion successfull......");
	}
	else
	{
		x=last->llink;
		x->rlink=last->rlink;
		x->rlink->llink=x;
		free(last);
		last=x;
		printf("\ndeletion successfull......");
	}
	return last;
}

n* delete_front(n *last)
{
	n *x;
	if(last==NULL)
	{
		printf("\nno list exist........");
	}
	else if(last->rlink==last)
	{
		free(last);
		last=NULL;
		printf("\ndeletion successfull.........");
	}
	else
	{
		x=last->rlink;
		x->rlink->llink=last;
		last->rlink=x->rlink;
		free(x);
		printf("\ndeletion successfull......");
	}
	return last;
}
void search(n *last)
{
	n *ptr;
	int val;
	if(last==NULL)
	{
		printf("\nno list exist......");
		return;
	}
	else
	{
		ptr=last->rlink;
		printf("\nenterb the value you want to find.......:");
		scanf("%d",&val);
		if(last->info==val)
		{
			printf("\nvalue is in the list....");
			return;
		}
		while(ptr!=last)
		{
			if(ptr->info==val)
			{	
				printf("\nvalue is in the list....");
				return;
			}
			ptr=ptr->rlink;
		}
	}	
	printf("\nvalue not in the list.....");
}


int main()
{
	n *ptr;
	int ch,chc,val;
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
	while(1)
	{
		printf("\n\n...........MENU...........\n\n");
		printf("\n1.display\n2.search\n3.insert at begining\n4.insert at end\n5.delete at begining\n6.delete at end\n0.exit");
		printf("\n\nenter your choice......: ");
		scanf("%d",&chc);
		switch(chc)
		{
			case 1: display(last);	
					break;
			case 2: search(last);
					break;		
			case 3: printf("\nenter value you want to insert...: ");
					scanf("%d",&val);
					last=insert_front(last,val);
					break;
			case 4: printf("\nenter value you want to insert...: ");
					scanf("%d",&val);
					last=insert_end(last,val);
					break;	
			case 5: last=delete_front(last);
					break;
			case 6: last=delete_end(last);
					break;
			case 0: exit(0);
			default: printf("\nenter valid choice: ");
					break;												
		}
		
	}
	return 0;
}
