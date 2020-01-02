#include<stdio.h>
#include<stdlib.h>
void insert_F();
void del_F();
void insert_R();
void del_R();
void display();
int *DQ,n,F=-1,R=-1;
void main()
{
int ch;
printf("\nEnter the size of your Queue: ");
scanf("%d",&n);
DQ=(int*)malloc(sizeof(int)*n);
while(1)
{
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
void insert_R()
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
DQ[R]=item;
}
}
void del_F()
{
if(F==-1)
printf("\nSorry!!Underflow......");
else
{
printf("\n%d element is deleted.",DQ[F]);
if(F==R)
F=R=-1;
else
F=F+1;
}
}
void insert_F()
{
int item;
if(F==0)
printf("\nSorry!!Overflow......");
else
{
printf("\nEnter the item: ");
scanf("%d",&item);
if(F==-1&&R==-1)
F=R=0;
else
F--;
DQ[F]=item;
}
}
void del_R()
{
if(R==-1)
printf("\nSorry!!Underflow......");
else
{
printf("\n%d element is deleted.",DQ[F]);
if(F==R)
F=R=-1;
else
R--;
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
printf(" %d",DQ[i]);
}
}
