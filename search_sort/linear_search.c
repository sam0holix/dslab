#include<stdio.h>
int linear(int* ,int ,int );
void print(int* ,int );
void insert(int* ,int );
void main()
{
int a[10],f,n,k;
printf("enter the the size of array:");
scanf("%d",&n);
insert(a,n);
printf("enter the element to search: ");
scanf("%d",&k);
printf("\n------------------------------------------------------\n");
printf("you have enter:");
print(a,n);
printf("\n------------------------------------------------------\n");
f=linear(a,n,k);
if(f!=0)
printf("Found at position %d.",f);
else
printf("Sorry,the data not found");
}
void insert(int* a,int n)
{
int i;
for(i=0;i<n;i++)
{
printf("enter the element: ");
scanf("%d",&a[i]);
}
}
void print(int* a,int n)
{
int i;
for(i=0;i<n;i++)
{
printf("%4d ",a[i]);
}
}
int linear(int* a,int n,int k)
{
int i,f;
for(i=0;i<n;i++)
{
if(a[i]==k)
{
f=i+1;
break;
}
}
return f;
}
