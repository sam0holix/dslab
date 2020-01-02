#include<stdio.h>
#include<stdlib.h>
void bubble(int*,int);
void print(int* ,int );
void insert(int* ,int );
void main()
{
int a[10],i,n;
printf("enter the the size of array:");
scanf("%d",&n);
insert(a,n);
printf("\n-------------------------------------------------------------------------\n");
printf("you have enter:");
print(a,n);
printf("\n-------------------------------------------------------------------------\n");
bubble(a,n);
printf("\n-------------------------------------------------------------------------\n");
printf("\n your sorted dataset is:");
print(a,n);
printf("\n-------------------------------------------------------------------------\n");
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
void bubble(int *a,int n)
{
int i,j,f=1,t;
for(i=1;i<n&&f==1;i++)
{
f=0;
for(j=0;j<=n-i;j++)
if(a[j]>a[j+1])
{
f=1;
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}
}
}
