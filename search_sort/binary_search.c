#include<stdio.h>
int binary(int* p,int lb,int ub,int key)
{
int mid;
if(lb>ub)
return 0;
else
{
mid=(lb+ub)/2;
if(key==p[mid])
return mid+1;
else if(key<p[mid])
binary(p,lb,(mid-1),key);
else
binary(p,(mid+1),ub,key);
}
}
void main()
{
int a[43],n,key,i,flag;
printf("enter the no. of data set: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter data: ");
scanf("%d",&a[i]);
}
printf("\n----------------------------------------------------------------\n");
printf("list: ");
for(i=0;i<n;i++)
printf("\t%d",a[i]);
printf("\n----------------------------------------------------------------\n");
printf("\n enter the element to search:");
scanf("%d",&key);
flag=binary(a,0,n-1,key);
if(flag==0)
printf("Sorry,Data not found.");
else
printf("Found at position %d.",flag);
}
