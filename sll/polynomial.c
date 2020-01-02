#include<stdio.h>
#include<stdlib.h>
//Structure of the list:
struct element
{
int coeff,power;
struct element *link;
};
typedef struct element ele;
#define getnode() (ele*)malloc(sizeof(ele))
ele* createpoly(ele*);
void show_poly(ele*);
ele* addition(ele*,ele*);
ele* subtraction(ele*,ele*);
ele* multiply(ele*,ele*);
ele* del(ele*,ele*);
int main()
{
ele *h1=NULL,*h2=NULL;
h1=createpoly(h1);
show_poly(h1);
h2=createpoly(h2);
show_poly(h2);
printf("\nAfter Addition: ");
show_poly(addition(h1,h2));
printf("\nAfter Substraction:");
show_poly(subtraction(h1,h2));
printf("\nAfter multiplication:");
show_poly(multiply(h1,h2));
}
ele* createpoly(ele *head)
{
ele *ptr,*current;int i,n;
printf("\nenter the degree of the polynomial: ");
scanf("%d",&n);
for(i=n;i>=0;i--)
{
ptr=getnode();
ptr->link=NULL;
ptr->power=i;
printf("enter the coefficient of x^%d: ",i);
scanf("%d",&ptr->coeff);
if(head==NULL)
head=ptr;
else
current->link=ptr;
current=ptr;
}
return head;
}
void show_poly(ele *head)
{
ele *x;
x=head;
printf("\nThe polynomial is:\n");
while(x!=NULL)
{
if(x->coeff!=0)
printf("+(%d)x^%d",x->coeff,x->power);
x=x->link;
}
}
ele* addition(ele *h1,ele *h2)
{
ele *ptr1,*ptr2,*h3=NULL,*ptr3,*current;
ptr1=h1;ptr2=h2;
while(ptr1!=NULL&&ptr2!=NULL)
{
ptr3=getnode();
ptr3->link=NULL;
if(ptr2->power==ptr1->power)
{
ptr3->coeff=ptr2->coeff+ptr1->coeff;
ptr3->power=ptr1->power;
ptr1=ptr1->link;
ptr2=ptr2->link;
}
else if(ptr1->power>ptr2->power)
{ptr3->coeff=ptr1->coeff;
ptr3->power=ptr1->power;
ptr1=ptr1->link;
}
else
{
ptr3->coeff=ptr2->coeff;
ptr3->power=ptr2->power;
ptr2=ptr2->link;
}
if(h3==NULL)
h3=ptr3;
else
current->link=ptr3;
current=ptr3;
}
while(ptr2!=NULL)
{
ptr3=getnode();
ptr3->link=NULL;
ptr3->coeff=ptr2->coeff;
ptr3->power=ptr2->power;
ptr2=ptr2->link;
if(h3==NULL)
h3=ptr3;
else
current->link=ptr3;
current=ptr3;
}
return h3;
}
ele* subtraction(ele *h1,ele *h2)
{
ele *ptr1,*ptr2,*h3=NULL,*ptr3,*current;
ptr1=h1;ptr2=h2;
while(ptr1!=NULL&&ptr2!=NULL)
{
ptr3=getnode();
ptr3->link=NULL;
if(ptr2->power==ptr1->power)
{
ptr3->coeff=ptr1->coeff-ptr2->coeff;
ptr3->power=ptr1->power;
ptr1=ptr1->link;
ptr2=ptr2->link;}
else if(ptr1->power>ptr2->power)
{
ptr3->coeff=ptr1->coeff;
ptr3->power=ptr1->power;
ptr1=ptr1->link;
}
else
{
ptr3->coeff=0-ptr2->coeff;
ptr3->power=ptr2->power;
ptr2=ptr2->link;
}
if(h3==NULL)
h3=ptr3;
else
current->link=ptr3;
current=ptr3;
}
while(ptr2!=NULL)
{
ptr3=getnode();
ptr3->link=NULL;
ptr3->coeff=ptr2->coeff;
ptr3->power=ptr2->power;
ptr2=ptr2->link;
if(h3==NULL)
h3=ptr3;
else
current->link=ptr3;
current=ptr3;
}
return h3;
}
ele* multiply(ele *h1,ele *h2)
{
ele *ptr1,*ptr2,*h3=NULL,*ptr3,*current,*h4=NULL;
int f=0;
ptr2=h2;
while(ptr2!=NULL)
{
ptr1=h1;
while(ptr1!=NULL)
{
ptr3=getnode();
ptr3->link=NULL;
ptr3->coeff=ptr1->coeff*ptr2->coeff;ptr3->power=ptr1->power+ptr2->power;
if(h3==NULL)
h3=ptr3;
else
current->link=ptr3;
current=ptr3;
ptr1=ptr1->link;
}
ptr2=ptr2->link;
}
//show_poly(h3);
for(ptr1=h3;ptr1!=NULL;ptr1=ptr1->link)
{
ptr3=getnode();
ptr3->link=NULL;
f=0;
for(ptr2=ptr1->link;ptr2!=NULL;ptr2=ptr2->link)
{
if(ptr2->power==ptr1->power)
{
ptr3->power=ptr2->power;
ptr3->coeff=ptr2->coeff+ptr1->coeff;
//printf("\nptr->%dx^%d\n",ptr3->coeff,ptr3->power);
f=1;
h3=del(ptr2,h3);
//show_poly(h3);
break;
}
}
if(f==0)
{
ptr3->coeff=ptr1->coeff;
ptr3->power=ptr1->power;
}
if(h4==NULL)
h4=ptr3;
else
current->link=ptr3;
//printf("\nptr->%dx^%d\n",ptr3->coeff,ptr3->power);
current=ptr3;
}
return h4;
}
//Delete()
ele* del(ele *ptr,ele *head)
{
ele* x;
if(ptr==head)
head=head->link;else
{
x=head;
while(x->link!=ptr)
x=x->link;
x->link=ptr->link;
}
free(ptr);
return head;
}
