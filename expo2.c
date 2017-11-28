#include<stdio.h>
int power(int base,int pow)
{
	int n,temp;
	if(pow==0)
		return 1;
	temp=power(base,pow/2);
	if(pow%2==0)
		return(temp*temp);
	else
		return(base*temp*temp);
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
