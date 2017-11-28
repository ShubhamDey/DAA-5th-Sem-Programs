#include<stdio.h>
int partition(int a[],int p,int r);
void quicksort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}
int partition(int a[],int p,int r)
{
	int i=(p-1);
	int j,temp;
	for(j=p;j<=r-1;j++)
	{
		if(a[j]<=a[r])
		{
			i=i+1;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[r];
	a[r]=a[i+1];
	a[i+1]=temp;
	return(i+1);
}
main()
{
	int p=0;
	int a[100],n,i;
	printf("Enter no of elements in an array:");
	scanf("%d",&n);
	int r=n;
	printf("Enter the numbers:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(a,p,r);
	printf("The sorted list\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
