#include<stdio.h>
void print(int* ,int );
void insert(int* ,int );
void quicksort(int*,int,int);
int partition(int*,int,int);
void main(){
int a[10],i,n;
printf("enter the the size of array:");
scanf("%d",&n);
insert(a,n);
printf("\n-------------------------------------------------------------------------\n");
printf("you have enter:");
print(a,n);
printf("\n-------------------------------------------------------------------------\n");
quicksort(a,0,n-1);
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
void quicksort(int A[],int p,int r)
{
int q;
if(p<r)
{
  q=partition(A,p,r);
//printf("\npart=%d\n",q);
quicksort(A,p,q-1);
quicksort(A,q+1,r);
}
}
int partition(int A[],int p,int r)
{
int i,j,pivot,t;
pivot=A[p];
i=p;
j=r;
while(1)
{
while((A[i]<pivot)&&(A[i]!=pivot))
{
i++;
}
while((A[j]>pivot)&&(A[j]!=pivot))
{
j--;
}
if(i<j)
{
t=A[i];
A[i]=A[j];
A[j]=t;
}
else
return j;
}
}
