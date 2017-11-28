#include<stdio.h>
void buildmaxheap(int a[],int n);
void maxheapify(int a[],int n,int i);
void heapsort(int a[],int n)
{
	int i,heapsize=n,temp;
	buildmaxheap(a,n);
	for(i=n;i>=1;i--)
	{
		temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		heapsize=heapsize-1;
		maxheapify(a,heapsize,0);
	}
}
void buildmaxheap(int a[],int n)
{
	int i;
	for(i=(n/2);i>=0;i--)
		maxheapify(a,n,i);
}
void maxheapify(int a[],int n,int i)
{
	int heapsize=n,largest,temp;
	int l=(2*i)+1;
	int r=(2*i)+2; 	
	if(l<=heapsize && a[l]>a[i])
		largest=l;
	else
		largest=i;
	if(r<=heapsize && a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		maxheapify(a,n,largest);
	}
}
main()
{
	int a[100],n,i;
	printf("Enter no of elements in an array:");
	scanf("%d",&n);
	printf("Enter the numbers:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	heapsort(a,n-1);
	printf("The sorted list\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
