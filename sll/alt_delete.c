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
n* list_creation();
n* only_even(n*);
//main()
int main()
{
int m;
n *head=NULL;
head=list_creation();
printf("\n\tThe list is:\n");
display(head);
while(1)
{
printf("\n Press 1 to delete alternate\n Press 2 to display the list\n Press 3 to exit.");
printf("\nEnter your choice: ");
scanf("%d",&m);
switch(m)
{
case 1:
head=only_even(head);
break;
case 2:
printf("\n\tThe list is:");
display(head);
break;case 3:
return 0;
default: printf("Wrong INput...\n");
}
}
}
//List_Creation()
n* list_creation()
{
n *head=NULL,*current,*x,*ptr;
int ch;
printf("\nLinked_List Creation: \n");
while(1){
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
return head;
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
printf("\n------------------------------------------------------------\n");
}n* only_even(n *head)
{
n *x,*ptr=NULL,*w;
int no=0; x=head;
while(x!=NULL)
{
no++;
if(no%2!=0)
{
if(ptr!=NULL)
free(ptr);
if(x==head)
{
ptr=head;
head=head->link;
}
else
{
w->link=x->link;
ptr=x;
}
}
w=x;
x=x->link;
}
return head;
}
