#include<stdio.h>
int power(int base,int pow)
{
	int n;
	if(pow==0)
		return 1;
	else
	{
		if(pow%2==0)
		{
			n=power(base,pow/2);
			return(n*n);
		}
		else
		{
			n=power(base,pow/2);
			return(base*n*n);
		}
	}
}
main()
{
	int base,pow;
	printf("Enter base:");
	scanf("%d",&base);
	printf("Enter power:");
	scanf("%d",&pow);
	printf("The result is:%d",power(base,pow));
}
