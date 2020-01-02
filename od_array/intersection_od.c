 #include<stdio.h>


void intersection(int a[], int b[], int n, int m)
{
	int i = 0, j = 0;

	while (i < n && j < m)
	{

		if (a[i] > b[j])
		{
			j++;
		}

		else
		if (b[j] > a[i])
		{
			i++;
		}
		else
		{

			printf("%d\t",a[i]);
			i++;
			j++;
		}
	}
}

int main()
{
	int a[10],b[10],i,n,m;
  printf("\nHow many elements for the 1st array : ");
  scanf("%d",&n);
  printf("\nHow many elements for the 2nd array : ");
  scanf("%d",&m);
  printf("\nEnter the elements of the 1st array : \n");
  for(i=0;i<n;i++) {
    printf("\nEnter the %dth element : ",i+1);
    scanf("%d",&a[i]);
  }
  i=0;
  printf("\nEnter the elements of the 2nd array : \n");
  for(i=0;i<n;i++) {
    printf("\nEnter the %dth element : ",i+1);
    scanf("%d",&b[i]);
  }
	intersection(a, b, n, m);
}
