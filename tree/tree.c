#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *lc,*rc;
};
typedef struct node bin;
int c=0;
void print(bin*);
int minimum(bin*);
int maximum(bin*);
int search(bin*,int,int);
void display_pre(bin *);
void display_in(bin *);
void display_post(bin *);
void create(bin*);
int main()
{
bin *root=NULL,*ptr;
int ch,key;
ptr=(bin*)malloc(sizeof(bin));
printf("\nenter the info for the root: ");
scanf("%d",&ptr->info);
ptr->lc=ptr->rc=NULL;
root=ptr;
create(root);
while(1)
{
printf("\n*** MENU ***\n1. print\n2. leaves\n3. search\n4. max,min\n5.Exit\nenter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\nPreorder traversal: ");
display_pre(root);
printf("\nInorder traversal: ");
display_in(root);
printf("\nPostorder traversal: ");
display_post(root);
break;
case 2: //printf("\nThere are %d no of leaves and the leaves are:",c);
print(root);
printf("\nThere are %d no of leaves and the leaves are:",c);
break;
case 3: printf("Enter the element to searched: ");
scanf("%d",&key);
key=search(root,key,0);
if(key==0)
printf("\nNode not found.....");
else
printf("\nNode found.....");
break;
case 4: printf("\nThe max element is: %d",maximum(root));
printf("\nThe min element is: %d",minimum(root));
break;
case 5: exit(0);
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
if(root==NULL)
return;
printf("%d ",root->info);
display_pre(root->lc);
display_pre(root->rc);
}
void display_in(bin *root)
{
if(root==NULL)
return;
display_in(root->lc);
printf("%d ",root->info);
display_in(root->rc);
}
void display_post(bin *root)
{
if(root==NULL)
return;
display_post(root->lc);
display_post(root->rc);
printf("%d ",root->info);
}
int maximum(bin *root)
{
int m,m1=0,m2=0;
m=root->info;
if(root->lc!=NULL)
{
m1=maximum(root->lc);
if(m1>m)
m=m1;
}
if(root->rc!=NULL)
{
m1=maximum(root->rc);
if(m1>m)
m=m1;
}
/*
if(m1>m2)
m=m1;
else
m=m2;*/
//printf("The max element is: %d",m);
return m;
}
int minimum(bin *root)
{
int m,m1=0,m2=0;
m=root->info;
if(root->lc!=NULL)
{
m1=minimum(root->lc);
if(m1<m)
m=m1;
}
if(root->rc!=NULL)
{
m1=minimum(root->rc);
if(m1<m)
m=m1;
}
if(m1>m2)
m=m1;
else
m=m2;
//printf("The max element is: %d",m);
return m;
}
int search(bin *root,int ch,int f)
{
if(root!=NULL&&f==0)
{
if(root->info==ch)
{
//printf("Node found....");
f=1;
return;
}
else if(f==0)
{
f=search(root->lc,ch,f);
f=search(root->rc,ch,f);
}
}
}
void print(bin *root){
bin *ptr;
ptr=root;
if(ptr->lc!=NULL||ptr->rc!=NULL)
{
if(ptr->lc!=NULL)
print(ptr->lc);
if(ptr->rc!=NULL)
print(ptr->rc);
}
else
{
c++;
printf(" %d",ptr->info);
}
}
