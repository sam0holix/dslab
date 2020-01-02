#include<stdio.h>
#include<stdlib.h>
//Structure of the list:
struct node
{
int info;
struct node *link;
};
typedef struct node n;
void display(n*);
n* insert_front(n*);
n* delete_front(n*);
n* insert_last(n*);
n* delete_last(n*);
n* insert_second(n*);
n* delete_second(n*);
n* insert_second_last(n*);
void display(n*);
void displaymm(n*);
void insert_after(n*);
n* insert_before(n*);
n* delete_from_anypos(n*);
void search(n*);
n* insert_at_anypos(n*);
n* delete_second_last(n*);
n* delete_after(n*);
n* delete_before(n*);
//main()
int main(){
int c;
n *head=NULL,*current,*x,*ptr;
int ch;
int r=-1;
printf("\nLinked_List Creation: \n");while(1){
ptr=(n*)malloc(sizeof(n));
printf("Enter the info: ");
scanf("%d",&ptr->info);
ptr->link=NULL;
if(head==NULL){
head=ptr;
current=ptr;
}
else{
current->link=ptr;
current=ptr;
}
printf("Do you to continue(1/0)?");
scanf("%d",&ch);
if(ch!=1)
break;
}
while(1){
printf("\n**MENU**");
printf("\n\tpress 1 to display the list...");
printf("\n\tpress 2 to search an info...");
printf("\n\tpress 3 to display the minimum and the maximum element in the list...");
printf("\n\tpress 4 to insert at the begining...");
printf("\n\tpress 5 to insert at the second...");
printf("\n\tpress 6 to insert at the last position...");
printf("\n\tpress 7 to insert at the second last position...");
printf("\n\tpress 8 to delete from the begining...");
printf("\n\tpress 9 to delete from the second...");
printf("\n\tpress 10 to deletion from the last...");
printf("\n\tpress 11 to deletion from the second last...");
printf("\n\tpress 12 to insert at any position...");
printf("\n\tpress 13 to delete from any position...");
printf("\n\tpress 14 to insert before a given data ...");
printf("\n\tpress 15 to insert after a given data...");
printf("\n\tpress 16 to delete before a given data ...");
printf("\n\tpress 17 to delete after a given data...");
printf("\n\tpress 18 to Exit...");
printf("\n\tEnter ur choice: ");
scanf("%d",&c);
switch(c)
{
case 1:
display(head);
break;
case 2:
search(head);break;
case 3:
displaymm(head);
break;
case 4:
head=insert_front(head);
break;
case 5:
head=insert_second(head);
break;
case 6:
head=insert_last(head);
break;
case 7:
head=insert_second_last(head);
break;
case 8:
head=delete_front(head);
break;
case 9:
head=delete_second(head);
break;
case 10:
head=delete_last(head);
break;
case 11:
head=delete_second_last(head);
break;
case 12:
head=insert_at_anypos(head);
break;
case 13:
head=delete_from_anypos(head);
break;
case 14:
head=insert_before(head);
break;
case 15:
insert_after(head);
break;
case 16:
head=delete_before(head);
break;
case 17:
head=delete_after(head);
break;
case 18:
exit(0);
}}
//
printf("\n\tpress 1 to insrt at the begining...");
return 0;
}
//display()
void display(n *head){
n *x;
printf("\nThe elements in the list: \n");
x=head;
if(x==NULL)
printf("\nThe List is empty.....\n");
while(x!=NULL)
{
printf("\t%d",x->info);
x=x->link;
}
}
//Display_min_max()
void displaymm(n *head)
{
n *x;
int min,max;
if(head==NULL)
printf("\nthe list is empty......\n");
else
{
min=head->info;
max=head->info;
x=head->link;
while(x!=NULL)
{
if(min>x->info)
min=x->info;
x=x->link;
}
x=head->link;
while(x!=NULL)
{
if(max<x->info)
max=x->info;
x=x->link;
}
printf("\n\tThe minimun element: %d and maximum element: %d.\n",min,max);
}
}
//insert_front()
n* insert_front(n *head){
n *ptr;ptr=(n*)malloc(sizeof(n));
printf("Enter the info: ");
scanf("%d",&ptr->info);
ptr->link=NULL;
if(head==NULL)
head=ptr;
else{
ptr->link=head;
head=ptr;
}
return head;
}
//insert_second()
n* insert_second(n *head)
{
n *ptr;
ptr=(n*)malloc(sizeof(n));
printf("Enter the info: ");
scanf("%d",&ptr->info);
ptr->link=NULL;
if(head==NULL)
printf("\n\tThe list is empty......");
else
{
ptr->link=head->link;
head->link=ptr;
}
return head;
}
//insert_end()
n* insert_last(n *head){
n *ptr,*x;
ptr=(n*)malloc(sizeof(n));
printf("Enter the info: ");
scanf("%d",&ptr->info);
ptr->link=NULL;
if(head==NULL)
head=ptr;
else
{
x=head;
while(x->link!=NULL)
x=x->link;
x->link=ptr;
}
return head;
}//insert_second_last()
n* insert_second_last(n *head)
{
n *x,*ptr;
ptr=(n*)malloc(sizeof(n));
printf("Enter the info: ");
scanf("%d",&ptr->info);
ptr->link=NULL;
if(head==NULL)
printf("\nSorry insertion not possible...");
else if(head->link==NULL)
head->link=ptr;
else
{
x=head;
while(x->link->link!=NULL)
x=x->link;
ptr->link=x->link;
x->link=ptr;
}
return head;
}
//Search()
void search(n *head)
{
int f=0,data,c=0;
n *x=head;
printf("enter the data to be searched: ");
scanf("%d",&data);
while(x!=NULL)
{
c++;
if(x->info==data)
{
f++;
break;
}
x=x->link;
}
if(f==0)
printf("\n\tthe info not found....\n");
else
printf("\n\tthe element found at %d position.\n",c);
}
//delete_begining()
n* delete_front(n* head){
n *p;if(head==NULL)
{
printf("\nSorry deletion not possible.......\n");
return 0;
}
p=head;
head=head->link;
free(p);
return head;
}
//delete_second()
n *delete_second(n *head)
{
n *ptr;
if(head==NULL)
printf("\nDeletion not possible");
else if(head->link==NULL)
printf("\n\tthere is only a single node.....\n");
else
{
ptr=head->link;
head->link=ptr->link;
free(ptr);
}
return head;
}
//Delete_last()
n* delete_last(n* head){
n *x;
if(head==NULL)
{
printf("\nSorry deletion not possible.......\n");
return 0;
}
else if(head->link==NULL)
head=NULL;
else
{
x=head;
while((x->link)->link!=NULL)
x=x->link;
free(x->link);
x->link=NULL;
}
return head;
}
//delete_second_last()
n* delete_second_last(n *head){
n *x,*ptr;
x=head;
if(x==NULL)
printf("\n\tDeletion not possible......\n");
else if(x->link==NULL)
printf("\n\tThere is only one node.....\n");
else
{
while(((x->link)->link)->link!=NULL)
x=x->link;
ptr=x->link;
x->link=ptr->link;
free(ptr);
}
return head;
}
//insert_atany_pos()
n* insert_at_anypos(n *head)
{
int p,f=0,i;
n *s,*ptr;
printf("\nenter the position at which you wnat to insert your data: ");
scanf("%d",&p);
if(p<=0)
printf("\nWrong input.......\n");
else if(p==1)
head=insert_front(head);
else
{
ptr=(n*)malloc(sizeof(n));
printf("Enter the data: ");
scanf("%d",&ptr->info);
ptr->link=NULL;
for(i=1,s=head;i<p-1;i++,s=s->link)
if(s==NULL)
{
f=1;
break;
}
if(f==1)
printf("\n\tPosition not found......\n");
else
{
ptr->link=s->link;
s->link=ptr;
}
}
return head;}
//Delete from any position()
n* delete_from_anypos(n *head)
{
int p,f=0,i;
n *s,*ptr;
printf("\nEnter the node position which is needed to be deleted: ");
scanf("%d",&p);
if(p<=0)
printf("\nWrong input.......\n");
else if(p==1)
head=delete_front(head);
else
{
for(i=1,s=head;i<p;i++,s=s->link)
if(s==NULL)
{
f=1;
break;
}
if(f==1)
printf("\n\tPosition not found......\n");
else
{
ptr=s->link;
s->link=ptr->link;
free(ptr);
}
}
return head;
}
//insert_after()
void insert_after(n *head)
{
int data,f=0;
n *x,*ptr;
ptr=(n*)malloc(sizeof(n));
printf("\nEnter the data to be inserted: ");
scanf("%d",&ptr->info);
ptr->link=NULL;
printf("\nEnter the data after which you want to insert: ");
scanf("%d",&data);
if(head->info==data)
{
ptr->link=head;
head=ptr;
}
x=head;
while(x->info!=data){
if(x==NULL)
{
f=1;
break;
}
x=x->link;
}
if(f==1)
printf("\n\tData not found.....\n");
else
{
ptr->link=x->link;
x->link=ptr;
}
}
//insert_before()
n* insert_before(n *head)
{
  int data,f=0;
  n *x,*ptr,*y;
  ptr=(n*)malloc(sizeof(n));
  printf("\nEnter the data to be inserted: ");
  scanf("%d",&ptr->info);
  ptr->link=NULL;
  printf("\nEnter the data after which you want to insert: ");
  scanf("%d",&data);
  x=head;
  while(x->info!=data)
  {
  if(x==NULL)
  {
    f=1;
    break;
  }
  y=x;
  x=x->link;
  }
  if(f==1)
  printf("\n\tData not found.....\n");
  else
  {
  ptr->link=y->link;
  y->link=ptr;
  }
  return head;
}

n* delete_after(n *head)
{
int no,f=0;
n *x,*y;
printf("\nEnter the data: ");
scanf("%d",&no);
if(head==NULL)
printf("\nThe list is empty......");
else if(head->link==NULL)
printf("\n deletion not possible...");
else
{
x=head;
while((x->link)->info!=no)
{
if(x->link==NULL)
{
f=1;
break;
}
x=x->link;
}
if(f==1)
printf("\nDeletion not possible....");
else
{
if(x->link==NULL)
printf("\ndeletion not possible......");
else
{
y=x->link;
x->link=y->link;
free(y);
}
}
}
return head;
}
//delete_before()
n* delete_before(n *head)
{
int no,f=0;
n *x,*y;
printf("\nEnter the data: ");
scanf("%d",&no);
if(head==NULL)
printf("\nThe list is empty...");
else if(head->link==NULL)
printf("deletion not possible......\n");
else if(head->link->info==no){
x=head;
head=head->link;
free(x);
}
else
{
x=head;
while((x->link)->info!=no)
{
if(x->link==NULL)
{
f=1;
break;
}
y=x;
x=x->link;
}
if(f==1)
printf("\nDeletion not possible....");
else
{
if(x->link==NULL)
printf("\nThis is the last node......");
else
{
y=x->link;
x->link=y->link;
free(y);
}
}
}
return head;
}
