#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *lc,*rc;
};
typedef struct node bin;
int top=-1;
bin *stack[100];
/*------------------------------------------------------------------------------------------------*/
void push(bin *item)
{
top=top+1;
stack[top]=item;
}
bin* pop()
{
bin *item;
if(top==-1)
printf("\nSorry!!Underflow..");
else
{
item=stack[top];
top=top-1;
}
return item;
}
/*----------------------------------------------------------------------------------------------------*/
void display_pre(bin *);
void display_in(bin *);
void display_post(bin *);
void create(bin*);
int main()
{
bin *root=NULL,*ptr;
int ch;
ptr=(bin*)malloc(sizeof(bin));
printf("\nenter the info for the root: ");
scanf("%d",&ptr->info);
ptr->lc=ptr->rc=NULL;
root=ptr;
create(root);
while(1)
{
printf("\n*** MENU ***\n1. preorder\n2. inorder\n3. postorder\n4. exit\nenter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1: display_pre(root);
break;
case 2: display_in(root);
break;
case 3: display_post(root);
break;
case 4: exit(0);
}
}
return 0;
}
void create(bin *root)
{
bin *ptr;
int ans;
printf("\ndo you want to create the left child of %d : (1-Yes/0-No)? ",root->info);
scanf("%d",&ans);
if(ans==1)
{
ptr=(bin*)malloc(sizeof(bin));
printf("\nenter the info for the left child: ");
fflush(stdin);
scanf("%d",&ptr->info);
ptr->lc=ptr->rc=NULL;
root->lc=ptr;
create(root->lc);
}
else
root->lc=NULL;
printf("\ndo you want to create the right child of %d : (1-Yes/0-No)? ",root->info);
scanf("%d",&ans);
if(ans==1)
{
ptr=(bin*)malloc(sizeof(bin));
printf("\nenter the info for the right child: ");
fflush(stdin);
scanf("%d",&ptr->info);
ptr->lc=ptr->rc=NULL;
root->rc=ptr;
create(root->rc);
}
else
root->rc=NULL;
}
void display_pre(bin *root)
{
bin* ptr;
push(root);
while(top!=-1)
{
ptr=pop();
printf("%d ",ptr->info);
if(ptr->rc!=NULL)
push(ptr->rc);
if(ptr->lc!=NULL)
push(ptr->lc);
}
}
void display_in(bin *root)
{
bin *ptr,*x;
ptr=root;
while(ptr!=NULL||top!=-1)
{
if(ptr!=NULL)
{
push(ptr);
ptr=ptr->lc;
}
else
{
ptr=pop();
printf("%d ",ptr->info);
ptr=ptr->rc;
}
}
}
void display_post(bin *root)
{
bin *ptr,*x;
ptr=root;
while(ptr!=NULL||top!=-1)
{
if(ptr!=NULL)
{
if(stack[top]!=ptr)
push(ptr);
if(ptr->rc!=NULL)
push(ptr->rc);
ptr=ptr->lc;
}
else
{
x=pop();
printf("%d ",x->info);
}
}
}
