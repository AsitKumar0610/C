#include<stdio.h>
#include<stdlib.h>
int main(){
	int *a,n,c,i,j,d=0;
	printf("\nEnter the size  ");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("\nEnter the array elements  \n");
	for( i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for( j=0;j<n;j++)
		{
			if(a[i]==a[j] && i!=j)
				c++ ;
		}
			if(c==3)
				break;
	}
		if(c==3)
			printf("\nThe third repeating element is  %d",a[i]);
		else
			printf("\nNot found");
		return 0;
}
