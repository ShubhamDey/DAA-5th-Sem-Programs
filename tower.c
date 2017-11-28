#include<stdio.h>
void tower(int n,char S, char A, char D)
{
	if(n==1)
	{
		printf("\n move disk %d from %c to %c ",n,S,D);
		return;
	}
	tower(n-1,S,D,A);
	printf("\n move disk %d from %c to %c ",n,S,D);
	tower(n-1,A,S,D);
	return;
}

main()
{
	int n;
	printf("\n enter number of disks ");
	scanf("%d",&n);
	tower(n,'A','B','C');
}
