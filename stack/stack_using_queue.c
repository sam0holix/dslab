#include<stdio.h>
#include<stdlib.h>
struct element
{
int data;
struct element *next;
};
typedef struct element queue;
void rev(queue*);
void peep(queue*);
void insert(queue **,queue **,int );
int del(queue **,queue **);
void show_stack(queue *);
int main()
{
int ch,k;
queue *f1=NULL, *r1=NULL,*f2=NULL,*r2=NULL;
while(1)
{
printf("\nPress 1 to push element.");
printf("\nPress 2 to pop element.");
printf("\n Press 3 to display.");
printf("\n Press 4 to peep.");
printf("\n press 9 to terminate.");
printf("\n Enter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n Enter the element: ");
scanf("%d",&k);
insert(&f1,&r1,k);
break;
case 2:
if(f1==NULL&&r1==NULL)
{
printf("\n stack empty.pop not possible.\n");
break;
}
while(f1!=r1)
insert(&f2,&r2,del(&f1,&r1));
k=del(&f1,&r1);
while(f2!=NULL&&r2!=NULL)
insert(&f1,&r1,del(&f2,&r2));
printf("\n Poped elenent is: %d.",k);
break;
case 3:
show_stack(f1);
break;
case 4:
peep(r1);
break;
case 9:
exit(0);
default:
printf("\n Invalid input.");
}
}
}
void peep(queue *top)
{
printf("\n------------------------------------\n");
if(top==NULL)
printf("\nSorry!!Underflow..");
else
printf("THe top most element is: %d",top->data);
printf("\n------------------------------------\n");
}
void insert(queue **f,queue **r,int k)
{
queue *ptr;
ptr=(queue *)malloc(sizeof(queue));
ptr->data=k;
ptr->next=NULL;
if(*f==NULL&&*r==NULL)
{
*f=*r=ptr;
}
else
{
(*r)->next=ptr;
(*r)=(*r)->next;
}
}
int del(queue **f,queue **r)
{
queue *s;
int i;
s=*f;
i=s->data;
if(*f==*r){
*f=*r=NULL;}
else
*f=(*f)->next;
free(s);
return i;
}
void rev(queue *s)
{
if(s!=NULL)
{
rev(s->next);
printf("\t%d",s->data);
}
}
void show_stack(queue *front)
{
queue *s;
printf("\n------------------------------------\n");
s=front;
if(s==NULL)
printf("\n Stack is empty.");
else
{
printf("\n List:");
rev(s); }
printf("\n");
printf("\n------------------------------------\n");
}
