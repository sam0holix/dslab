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
n* reverse_list(n*);
//main()
int main()
{
n *head=NULL,*h1=NULL;
head=list_creation();
printf("\n\tThe list is:\n");
display(head);
h1=reverse_list(head);
printf("\n\tThe reverse:");
display(h1);
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
}printf("Do you to continue(1/0)?");
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
}
n* reverse_list(n *curr)
{
n *prev=NULL,*next=NULL;
while(curr!=NULL)
{
next=curr->link;
curr->link=prev;
prev=curr;
curr=next;
}
return prev;
}
