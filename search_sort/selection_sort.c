#include<stdio.h>
void selection(int* ,int );
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
selection(a,n);
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
void selection(int* a,int n)
{
int i,j,k;
for(i=0;i<n-1;i++)
{
for(j=1+i;j<=n-1;j++)
{
if(a[i]>a[j])
{
k=a[i];
a[i]=a[j];
a[j]=k;
}
}
}
}
