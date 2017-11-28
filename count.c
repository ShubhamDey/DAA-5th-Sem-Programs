#include<stdio.h>
int count_sort(int a[],int k,int n)
{
	int c[100],i,j;
	for(i=1;i<=k;i++)
		c[i]=0;
	for(j=0;j<n;j++)
		c[a[j]]++;
	for(i=1;i<=k;i++)
	{
		if(c[i]!=0)
		{
			for(j=0;j<c[i];j++)
				printf(" %d",i);
		}
	}
}
int main()
{
	int a[100],j,n,i;
	printf("Enter no of elements in an array:");
	scanf("%d",&n);
	printf("Enter the numbers:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int k=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>k)
		k=a[i];
	}
	printf("\nElements after sorting:");
	count_sort(a,k,n);
}
