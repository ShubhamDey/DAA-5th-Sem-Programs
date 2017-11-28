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
int ls(int k)
{
	int i,f=0,n=0;
	for(i=0;i<5;i++)
	{
		n++;
		if(a[i]==k)
		return i;
	}
	printf("Comparisions needed:%d",n);
	return -1;
}
int ls_rec(int *a,int k,int i)
{
	if(*a==k && i<6)
		return i;
	else if(i>=6)
		return -1;
	else
	{
		i++;
		ls_rec(*((&a)+i*sizeof(int)),k,i);
	}
}
main()
{
	int f,k;
	k=inp();
//	f=ls(k);
	f=ls_rec(a,k,0);
	if(f!=-1)
		printf("Found");
	else
		printf("Not found");
}	
