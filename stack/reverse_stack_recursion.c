#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *link;
};
typedef struct node node;
void push(int);
int pop();
void display();
void peep();
void reverse();
void insertAtBottom(int);
node *top=NULL;
void main()
{
int ch,item;
while(1)
{
printf("\n\t**MENU**");
printf("\n\tpress 1 to insert an item in stack..");
printf("\n\tpress 2 to delete an item from the stack..");
printf("\n\tpress 3 to peep in the stack..");
printf("\n\tpress 4 to display the items in the stack..");
printf("\n\tpress 5 to reverse..");
printf("\n\tpress 6 to exit..");
printf("\n\tEnter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nEnter the item: ");
scanf("%d",&item);
push(item);
break;
case 2:
item=pop();
if(item!=-1)
printf("\n%d item is deleted.",item);
break;
case 3:
peep();
break;
case 4:
display();
break;
case 5:
reverse();
break;
case 6:
exit(0);
default:
printf("\nWRONG CHOICE..\n");
}
}
}
void peep()
{
if(top==NULL)
printf("\nSorry!!Underflow..");
else
printf("THe top most element is: %d",top->info);
}
void push(int item)
{
node *ptr;
ptr=(node*)malloc(sizeof(node));
ptr->link=NULL;
if(ptr==NULL)
printf("\nSorry!!Stack overflow");
else
{
ptr->link=top;
top=ptr;
top->info=item;
}
}
int pop()
{
int item=-1;
node *x;
if(top==NULL)
printf("\nSorry!!Underflow..");
else
{
x=top;
top=top->link;
item=x->info;
free(x);
}
return item;
}
void reverse()
{ int t;
if(top!=NULL)
{
t=pop();
reverse();
insertAtBottom(t);
}
}
void insertAtBottom(int item)
{ int t;
if(top==NULL)
push(item);
else
{
t=pop();
insertAtBottom(item);
push(t);
}
}
void display()
{
node *i;
if(top==NULL)
printf("\nSorry!!Underflow..");
else
{
i=top;
printf("\nThe elements in the stack:");
while(i!=NULL)
{
printf(" %d",i->info);
i=i->link;
}
}
}
