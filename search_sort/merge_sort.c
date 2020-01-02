#include<stdio.h>
#include<stdlib.h>
void marge(int*,int,int,int);
void margesort(int*,int,int);
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
margesort(a,0,n-1);
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
void margesort(int *list,int lb,int ub)
{
int mid;
if(lb<ub)
{
mid=(lb+ub)/2;
margesort(list,lb,mid);
margesort(list,mid+1,ub);
marge(list,lb,mid,ub);
}
}
void marge(int *list,int lb,int mid,int ub)
{
int j,i,m,k,l,p,temp[100];
i=lb;
k=1;
j=mid+1;
while((i<=mid)&&(j<=ub))
{
if(list[i]<list[j])
{
temp[k]=list[i];
i++;
}
else
{
temp[k]=list[j];
j++;
}
k++;
}
while(i<=mid)
{
temp[k]=list[i];
i++;
k++;
}
while(j<=ub)
{
temp[k]=list[j];
j++;
k++;
}
for(p=lb,m=1;p<=ub;p++,m++)
{
list[p]=temp[m];
}
}
