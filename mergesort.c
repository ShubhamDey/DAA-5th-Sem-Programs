#include<stdio.h>
void merge(int a[],int p,int q,int r);
void mergesort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}
void merge(int a[],int p,int q,int r)
{
	int i,k,j,L[100],R[100];
	int n1=(q-p+1);
	int n2=(r-q);
	for(i=0;i<=n1;i++)
		L[i]=a[p+i-1];
	for(j=0;j<=n2;j++)
		R[j]=a[q+j];
	L[n1+1]=9999;
	R[n2+1]=9999;
	i=1;
	j=1;
	for(k=p;k<=r;k++)
	{
		if(L[i]<R[j])
		{
			a[k]=L[i];
			i=i+1;
		}
		else
		{
			a[k]=R[j];
			j=j+1;
		}
	}
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
	mergesort(a,p,r-1);
	printf("The sorted list\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
