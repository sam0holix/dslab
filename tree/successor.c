#include<stdio.h>
#include<stdlib.h>
//Tree Structure
struct tree
{
int info;
struct tree *lc,*rc;
};
typedef struct tree bin;
int in[100],pre[100],post[100],i,j,k;
//Fn Declaration
void create(bin*);
void succ(bin*);
void display_pre(bin *);
void display_in(bin *);
void display_post(bin *);
void inorder(bin*);
void postorder(bin*);
void preorder(bin*);
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
printf("\n*** MENU ***\n1. print\n2. successor\n3. exit\nenter your choice: ");
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
case 2: succ(root);
break;
case 3: exit(0);
}
}
return 0;
}
//creating tree:
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
void preorder(bin *root)
{
if(root==NULL)
return;
//printf(" %d",root->info);
pre[i++]=root->info;
preorder(root->lc);
preorder(root->rc);
}
void inorder(bin *root)
{
if(root==NULL)
return;
inorder(root->lc);
//printf(" %d",root->info);
in[j++]=root->info;;
inorder(root->rc);
}
void postorder(bin *root)
{
if(root==NULL)
return;
postorder(root->lc);
postorder(root->rc);
//printf(" %d",root->info);
post[k++]=root->info;
}
void succ(bin *root)
{
int key,i1=0,j1=0,k1=0;
k=0,i=0,j=0;
inorder(root);
preorder(root);
postorder(root);
printf("\nEnter the node: ");
scanf("%d",&key);
while(i1<i)
{
if(pre[i1]==key)
break;
i1++;
}
while(j1<j)
{
if(in[j1]==key)
break;
j1++;
}
while(k1<k)
{
if(post[k1]==key)
break;
k1++;
}
printf("%d %d",k,k1);
if(j1==j-1)
printf("\nhas no inorder successor.");
else
printf("\ninorder Successor: %d.",in[j1+1]);
if(k1==k-1)
printf("\nhas no postorder successor.");
else
printf("\npostorder Successor: %d.",post[k1+1]);
if(i1==i-1)
printf("\nhas no preorder successor.");
else
printf("\npreorder Successor: %d.",pre[i1+1]);
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
