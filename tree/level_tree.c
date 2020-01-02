#include<stdio.h>
#include<stdlib.h>
//Tree Structure
struct tree
{
int info;
struct tree *lc,*rc;
};
typedef struct tree bin;
//Queue Structure
struct node
{
bin *data;
struct node *link;
};
typedef struct node node;
node *F=NULL,*R=NULL;
/*-----------------------------------------------------------------------------------------------*/
/*Queue Operation*/
void Qinsert(bin* item)
{
node *ptr;
ptr=(node*)malloc(sizeof(node));
ptr->link=NULL;
if(ptr==NULL)
printf("\nSorry!!Overflow......");
else
{
ptr->data=item;
if(F==NULL&&R==NULL)
F=R=ptr;
else
{
R->link=ptr;
R=ptr;
}
}
}
bin* Qdelete()
{
node *x;
if(F==NULL)
printf("\nSorry!!Underflow......");
else
{
x=F;
//printf("\n%d element is deleted.",x->data);
if(F==R)
F=R=NULL;
else
F=F->link;
//free(x);
}
return x->data;
}
/*---------------------------------------------------------------------------------------------------------------*/
//Fn Declaration
void create(bin*);
void BreadthwiseTraversal(bin*);
//Main()
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
printf("\nThe breadthwise trversal.");
BreadthwiseTraversal(root);
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
//Level Wise Traversal:
void BreadthwiseTraversal(bin *root)
{
bin *ptr;
Qinsert(root);
while(F!=NULL)
{
ptr=Qdelete();
printf("%d ",ptr->info);
if(ptr->lc!=NULL)
Qinsert(ptr->lc);
if(ptr->rc!=NULL)
Qinsert(ptr->rc);
}
}
