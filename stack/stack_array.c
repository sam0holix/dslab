#include<stdio.h>
#include<stdlib.h>
int push(int);
int pop(int);
void display(int);
void peep(int);
int *S,n;
void main()
{
int top=-1,ch;
printf("\nEnter the size of your stack: ");
scanf("%d",&n);
S=(int*)malloc(sizeof(int)*n);
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
int push(int top)
{
int item;
if(top==n-1)
printf("\nSorry!!Stack overflow");
else
{
top=top+1;
printf("\nEnter the item: ");
scanf("%d",&item);
S[top]=item;
}
return top;
}
int pop(int top)
{
if(top==-1)
printf("\nSorry!!Underflow..");
else
{
printf("%d has been deleted.",S[top]);
top=top-1;
}
return top;
}
void peep(int top)
{
if(top==-1)
printf("\nSorry!!Underflow..");
else
printf("THe top most element is: %d",S[top]);
}
void display(int top)
{
int i;
if(top==-1)
printf("\nSorry!!Underflow..");
else
{
i=top;
printf("\nThe elements in the stack:");
while(i>=0)
{
printf(" %d",S[i]);
i--;
}
}
}
