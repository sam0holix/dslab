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
n* insertbeg(n*);
n* insertend(n*);
n* deletebeg(n*);
n* deleteend(n*);
int search(n*,int);
n* insertany(n*,int);
n* deleteany(n*,int);
n* insertbefore(n*);n* insertafter(n*);
n* deletebefore(n*);
n* deleteafter(n*);
//main()
int main()
{
int c,k;
n *last=NULL,*current,*x,*ptr;
int ch;
int r=-1;
printf("\nLinked_List Creation: \n");
while(1){
ptr=(n*)malloc(sizeof(n));
printf("Enter the info: ");
scanf("%d",&ptr->info);
ptr->link=ptr;
if(last!=NULL)
{
ptr->link=last->link;
last->link=ptr;
}
last=ptr;
printf("Do you to continue(1/0)?");
fflush(stdin);
scanf("%d",&ch);
if(ch!=1)
{
//current->link=head;
break;
}
}
while(1){
printf("\n**MENU**");
printf("\n\tpress 1 to display the list...");
printf("\n\tpress 2 to search en element.....");
printf("\n\tpress 3 to insert an info at the begining...");
printf("\n\tpress 4 to insert an info at the end...");
printf("\n\tpress 5 to delete from the begining...");
printf("\n\tpress 6 to delete from the end...");
printf("\n\tpress 7 to insert at any position....");
printf("\n\tpress 8 to delete at any position....");
printf("\n\tpress 9 to insert before a given data ...");
printf("\n\tpress 10 to insert after a given data...");
printf("\n\tpress 11 to delete before a given data ...");printf("\n\tpress 12 to delete after a given data...");
printf("\n\tpress 18 to Exit...");
printf("\n\tEnterur choice: ");
scanf("%d",&c);
switch(c)
{
case 1:
display(last);
break;
case 2:
printf("\nEnter the element to search: ");
scanf("%d",&k);
k=search(last,k);
if(k==0)
printf("\nSorry,the data not found......\n");
else
printf("\nFound at %d position.....\n",k);
break;
case 3:
last=insertbeg(last);
break;
case 4:
last=insertend(last);
break;
case 5:
last=deletebeg(last);
break;
case 6:
last=deleteend(last);
break;
case 7:
last=insertany(last,0);
break;
case 8:
last=deleteany(last,0);
break;
case 9:
last=insertbefore(last);
break;
case 10:
last=insertafter(last);
break;
case 11:
last=deletebefore(last);
break;case 12:
last=deleteafter(last);
break;
case 18:
exit(0);
default: printf("\nWrong Input");
}
}
//
printf("\n\tpress 1 to insert at the begining...");
return 0;
}
void display(n *l)
{
n *x;
printf("\n----------------------------------------------------\n");
printf("The list: ");
if(l==NULL)
printf("\b\b is empty.");
else
{
x=l->link;
while(x!=l)
{
printf("%d ",x->info);
x=x->link;
}
printf("%d ",x->info);
}
printf("\n-----------------------------------------------------\n");
}
n* insertbeg(n *l)
{
n *ptr;
ptr=(n*)malloc(sizeof(n));
printf("\nEnter info: ");
scanf("%d",&ptr->info);
ptr->link=ptr;
if(l==NULL)
l=ptr;
else
{
ptr->link=l->link;
l->link=ptr;
}return l;
}
n* insertend(n *l)
{
n *ptr;
ptr=(n*)malloc(sizeof(n));
printf("\nEnter info: ");
scanf("%d",&ptr->info);
ptr->link=ptr;
if(l!=NULL)
{
ptr->link=l->link;
l->link=ptr;
}
l=ptr;
return l;
}
n* deletebeg(n *l)
{
n *ptr;
if(l==NULL)
printf("\nThe list is empty");
else if(l->link==l)
{
free(l);
l=NULL;
}
else
{
ptr=l->link;
l->link=ptr->link;
free(ptr);
}
return l;
}
n* deleteend(n *l)
{
n *ptr;
if(l==NULL)
printf("\nThe list is empty");
else if(l->link==l)
{free(l);
l=NULL;
}
else
{
ptr=l->link;
while(ptr->link!=l)
ptr=ptr->link;
ptr->link=l->link;
free(l);
l=ptr;
}
return l;
}
int search(n *l,int Key)
{
int f=0,c=0;
n *x;
if(l==NULL)
return 0;
x=l->link;
do
{
c++;
if(x->info==Key)
{
f=1;
break;
}
x=x->link;
}
while(x!=l->link);
if(f==1)
return c;
else
return 0;
}
n* insertany(n *l,int p)
{
n *s,*ptr;
int i,f=0,no=1;
s=l->link;
while(s!=l)
{no++;
s=s->link;
}
if(p==0)
{
printf("\nEnter the position: ");
scanf("%d",&p);
}
if(p<1)
printf("\nInsertion not possible.......");
else if(p==1)
l=insertbeg(l);
else if(p==no+1)
l=insertend(l);
else
{
for(i=1,s=l->link;i<p-1;i++,s=s->link)
if(s==l)
{
f=1;
break;
}
if(f==1)
printf("\n\tPosition not found......\n");
else
{
ptr=(n*)malloc(sizeof(n));
printf("Enter the data: ");
scanf("%d",&ptr->info);
ptr->link=ptr;
ptr->link=s->link;
s->link=ptr;
}
}
return l;
}
n* deleteany(n *l,int p)
{
n *s,*ptr;
int i,f=0,no=1;
s=l->link;
while(s!=l)
{
no++;
s=s->link;}
if(p==0)
{
printf("\nEnter the position: ");
scanf("%d",&p);
}
if(p<1)
printf("\nInsertion not possible.......");
else if(p==1)
l=deletebeg(l);
else if(p==no)
l=deleteend(l);
else
{
for(i=1,s=l->link;i<p-1;i++,s=s->link)
if(s==l)
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
return l;
}
n* insertbefore(n *l)
{
int k,s;
printf("\nEnter the value before which you want to insert: ");
scanf("%d",&k);
if(l==NULL)
printf("\nInsertion is not possible...");
else if((l->link)->info==k)
l=insertbeg(l);
else
{
s=search(l,k);
if(s!=0)l=insertany(l,s);
else
printf("\nData not found");
}
return l;
}
n* insertafter(n *l)
{
int k,s;
printf("\nEnter the value after which you want to insert: ");
scanf("%d",&k);
if(l==NULL)
printf("\nInsertion is not possible...");
else
{
s=search(l,k);
if(s!=0)
l=insertany(l,s+1);
else
printf("\nData not found");
}
return l;
}
n* deletebefore(n *l)
{
int k,s;
printf("\nEnter the value before which you want to delete: ");
scanf("%d",&k);
if(l==NULL)
printf("\nInsertion is not possible...");
else if((l->link)->info==k)
l=deleteend(l);
else
{
s=search(l,k);
if(s!=0)
l=deleteany(l,s-1);
else
printf("\nData not found");
}
return l;
}
n* deleteafter(n *l)
{
int k,s;
printf("\nEnter the value after which you waht to delete: ");
scanf("%d",&k);
if(l==NULL)
printf("\nInsertion is not possible...");
else if(l->info==k)
l=deletebeg(l);
else
{
s=search(l,k);
if(s!=0)
l=deleteany(l,s+1);
else
printf("\nData not found");
}
return l;
}
