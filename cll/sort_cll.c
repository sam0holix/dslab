#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *link;
}n;

n *last=NULL;

n* create(n*);
void display(n*);

int main()
{
	last=create(last);
	display(last);
	return 0;
}
n* create(n* last)
{
	n *ptr,*x,*y;
	int ch;
	while(1)
	{
		ptr=(n*)malloc(sizeof(n));
		printf("\nenter the value :");
		scanf("%d",&ptr->info);
		ptr->link=ptr;
		if(last==NULL)
		{
			last=ptr;
		}
		else
		{
			x=last->link;
			if(ptr->info<=x->info)
			{
				ptr->link=last->link;
				last->link=ptr;
			}
			else
			{
				while(x!=last && ptr->info>x->info)
				{
					y=x;
					x=x->link;
				}
				if(x->link==last)
				{
					ptr->link=last->link;
					last->link=ptr;
					last=ptr;
				}
				else
				{
					ptr->link=x;
					y->link=ptr;
				}
			}
		}
		printf("\ndo you want to continue?(1/0)...........");
		scanf("%d",&ch);
		if(ch!=1)
			break;
	}
	return last;
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
