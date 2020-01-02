#include<stdio.h>
#include<stdlib.h>
void insert();
void del();
void display();
int *Q,n,F=-1,R=-1;
void main()
{
int ch;
printf("\nEnter the size of your Queue: ");
scanf("%d",&n);
Q=(int*)malloc(sizeof(int)*n);
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
int item;
if(R==n-1)
printf("\nSorry!!Overflow......");
else
{
printf("\nEnter the item: ");
scanf("%d",&item);
if(F==-1&&R==-1)
F=R=0;
else
R=R+1;
Q[R]=item;
}
}
void del()
{
if(F==-1)
printf("\nSorry!!Underflow......");
else
{
printf("\n%d element is deleted.",Q[F]);
if(F==R)
F=R=-1;
else
F=F+1;
}
}
void display()
{
int i;
if(F==-1)
printf("\nSorry!!Underflow......");
else
{
printf("\nThe element in Queue:");
for(i=F;i<=R;i++)
printf(" %d",Q[i]);
}
}
