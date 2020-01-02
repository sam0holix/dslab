#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *link;
};
typedef struct node node;
node* push(node*);
node* pop(node*);
void display(node*);
void peep(node*);
void main()
{
int ch;
node *top=NULL;
while(1)
{
printf("\n\t**MENU**");
printf("\n\tpress 1 to insert an item in stack..");
printf("\n\tpress 2 to delete an item from the stack..");
printf("\n\tpress 3 to peep in the stack..");
printf("\n\tpress 4 to display the items in the stack..");
printf("\n\tpress 5 to exit..");
printf("\n\tEnter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
top=push(top);
break;
case 2:
top=pop(top);
break;
case 3:
peep(top);
break;
case 4:
display(top);
break;
case 5:
exit(0);
default:
printf("\nWRONG CHOICE..\n");
}
}
}
node* push(node *top)
{
int item;
node *ptr;
ptr=(node*)malloc(sizeof(node));
ptr->link=NULL;
if(ptr==NULL)
printf("\nSorry!!Stack overflow");
else
{
ptr->link=top;
top=ptr;
printf("\nEnter the item: ");
scanf("%d",&item);
top->info=item;
}
return top;
}
node* pop(node *top)
{
node *x;
if(top==NULL)
printf("\nSorry!!Underflow..");
else
{
x=top;
top=top->link;
printf("%d has been deleted.",x->info);
free(x);
}
return top;
}
void peep(node *top)
{
if(top==NULL)
printf("\nSorry!!Underflow..");
else
printf("THe top most element is: %d",top->info);
}
void display(node *top)
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
