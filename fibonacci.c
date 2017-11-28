#include<stdio.h>
#include<time.h>
int fibo(int n)
{
	int fibn;
	if(n==0 || n==1)
	{
		fibn=n;
		return(fibn);
	}
	fibn=fibo(n-2)+fibo(n-1);
	return(fibn);
}
main()
{
	int n,a,i;
	double t;
	clock_t start,stop;
//	printf("Enter the number of iterations:");
//	scanf("%d",&n);
	for(i=1;i<=45;i++)
	{
		start=clock();
		a=fibo(i);
		stop=clock();
		t=(double)(stop-start)/CLOCKS_PER_SEC;
		printf("\n%lf",t);
	}
//	printf("The Nth term of the series:%d",fibo(n));
}
