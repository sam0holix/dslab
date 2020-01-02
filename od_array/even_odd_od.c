#include <stdio.h>
void print(int *a,int n)
 {
    int i;



    for(i=0; i<n; i++)
    {

        	printf("%d  ",a[i]);


    }

 }
void function(int *a,int *b,int *c,int n)
{
    int i,j,k,temp;

       j=k=0;
    for(i=0; i<n; i++)
    {
        if(a[i]%2==0)
          b[j++]=a[i];
        else
          c[k++]=a[i];

    }

   printf("\n original array  \n");

    print(a,n);


    printf(" \n even array \n");

    print(b,j);
    printf(" \n odd array \n");

    print(c,k);


 }



int main()
{
    int a[10],b[10],c[20],i,j,k,n1,n2,n ;

    printf("Enter size of the  array : ");

	scanf("%d", &n);

	printf("Enter elements in array : ");

	for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }


    function(a,b,c,n);

    return 0;
}
