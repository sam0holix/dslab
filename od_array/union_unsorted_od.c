#include<stdio.h>

int main()
{
	int a1[20],a2[20],u[40],i,j,k,n,m,flag;

	printf("Enter size of first array:");
	scanf("%d",&n);
	printf("Enter elements of first array:\n");
	for(i=0;i<n;++i){
		scanf("%d",&a1[i]);
	}

	printf("\nEnter size of second array:");
	scanf("%d",&m);
	printf("Enter elements of second array:\n");
	for(i=0;i<m;++i){
		scanf("%d",&a2[i]);
	}

	k=0;
	for(i=0;i<n;++i){
		u[k]=a1[i];
		k++;
	}

	for(i=0;i<m;++i){
		flag=1;
		for(j=0;j<n;++j){
			if(a2[i]==a1[j]){
				flag=0;
				break;
			}
		}

		if(flag){
			u[k]=a2[i];
			k++;
		}
	}

	printf("\nUnion of two arrays is:\n");
	for(i=0;i<k;++i){
		printf("%d ",u[i]);
	}

    return 0;
}
