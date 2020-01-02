#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
};
typedef struct node node;
void insert();
void del();
void display();
node *F=NULL,*R=NULL;
void main()
{
int ch;
while(1)
{
printf("\n\t**MENU**");
printf("\n\tpress 1 to insert an item in queue..");
printf("\n\tpress 2 to delete an item from the queue..");
printf("\n\tpress 3 to display the items in the queue..");
printf("\n\tpress 4 to exit..");
printf("\n\tEnter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
insert();
break;
case 2:
del();
break;
case 3:
display();
break;
case 4:
exit(0);
default:
printf("\nWRONG CHOICE..\n");
}
}
}
void insert()
{
node *ptr;
ptr=(node*)malloc(sizeof(node));
ptr->link=NULL;
if(ptr==NULL)
printf("\nSorry!!Overflow......");
else
{
printf("\nEnter the item: ");
scanf("%d",&ptr->data);
if(F==NULL&&R==NULL)
F=R=ptr;
else
{
R->link=ptr;
R=ptr;
}
}
}
void del()
{
node *x;
if(F==NULL)
printf("\nSorry!!Underflow......");
else
{
x=F;
printf("\n%d element is deleted.",x->data);
if(F==R)
F=R=NULL;
else
F=F->link;
free(x);
}
}
void display()
{
node *i;
if(F==NULL)
printf("\nSorry!!Underflow......");
else
{
printf("\nThe element in Queue:");
for(i=F;i!=NULL;i=i->link)
printf(" %d",i->data);
}
}
