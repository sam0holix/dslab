#include<stdio.h>
#include<stdlib.h>
void insertion(int*,int);
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
insertion(a,n);
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
void insertion(int* a,int n)
{
int i,j,key;
for(j=1;j<=n-1;j++)
{
key=a[j];
i=j-1;
while(i>=0&&key<a[i])
{
a[i+1]=a[i];
i=i-1;
}
a[i+1]=key;
}
}
