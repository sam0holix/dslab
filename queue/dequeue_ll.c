#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
};
typedef struct node node;
void insert_F();
void del_F();
void insert_R();
void del_R();
void display();
node *F=NULL,*R=NULL;
void main()
{
int ch;
while(1)
{
printf("\n\t**MENU**");
printf("\n\t**MENU**");
printf("\n\tpress 1 to insert an item in queue from the rear end..");
printf("\n\tpress 2 to delete an item from the queue from the rear end..");
printf("\n\tpress 3 to insert an item in queue from the front end..");
printf("\n\tpress 4 to delete an item from the queue from the front end..");
printf("\n\tpress 5 to display the items in the queue..");
printf("\n\tpress 6 to exit..");
printf("\n\tEnter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
insert_R();
break;
case 2:
del_R();
break;
case 3:
insert_F();
break;
case 4:
del_F();
break;
case 5:
display();
break;
case 6:
exit(0);
default:
printf("\nWRONG CHOICE..\n");
}
}
}
void insert_F()
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
ptr->link=F;
F=ptr;
}
}
}
void del_R()
{
  node *x;
if(F==NULL)
printf("\nSorry!!Underflow......");
else
{
printf("\n%d element is deleted.",R->data);
if(F==R)
{
free(R);
F=R=NULL;
}
else
{
x=F;
while(x->link!=R)
x=x->link;
x->link=NULL;
free(R);
R=x;
}
}
}
void insert_R()
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
void del_F()
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
