#include<stdio.h>
int a[20];
int inp()
{
	int i,k;
	printf("Input 5 numbers:");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the number to search:");
	scanf("%d",&k);
	return k;
}
int bs(int k)
{
	int mid,n=0;
	int lb=0;
	int ub=5;
	while(lb<=ub)
	{
//		n++
		mid=(lb+ub)/2;
		if(a[mid]==k)
			return mid;
		if(a[mid]<k)
			lb=mid+1;
		else
			ub=mid-1;
	}
//	printf("Comaparisions needed:%d",n);
	return -1;
}
int bs_rec(int lb,int ub,int k)
{

	int mid;
	if(lb>ub)
		return -1;
	mid=(lb+ub)/2;
	if(a[mid]==k)
		return mid;
	if(a[mid]<k)
		bs_rec(mid+1,ub,k);
	else
		bs_rec(lb,mid-1,k);

}
main()
{
	int f,k;
	k=inp();
	f=bs(k);
//	f=bs_rec(0,5,k);
	if(f!=-1)
		printf("Found at %d",f);
	else
		printf("Not found");
}	
