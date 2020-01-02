#include<stdio.h>
#include<stdlib.h>
struct node
{
char info;
struct node *link;
};
typedef struct node node;
void Push(char);
void Pop();
node *top=NULL;
void main()
{
char str[100];
int i;
printf("\nEnter the string: ");
scanf("%s",str);
for(i=0;str[i]!='\0';i++)
Push(str[i]);
printf("\nThe string in reverse: ");
while(top!=NULL)
Pop();
}
void Push(char item)
{
node *ptr;
ptr=(node*)malloc(sizeof(node));
ptr->info=item;
ptr->link=NULL;
if(ptr==NULL)
printf("\nSorry!!Stack overflow");
else
{
ptr->link=top;
top=ptr;
}
}
void Pop()
{
node *x;
if(top==NULL)
printf("\nSorry!!Underflow..");
else
{
x=top;
top=top->link;
printf("%c",x->info);
free(x);
}
}
