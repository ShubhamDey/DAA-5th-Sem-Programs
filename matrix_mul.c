#include<stdio.h>
int m[100][100],s[100][100];
void matrix_chain_order(int p[],int length)
{
	int i,l,j,k,q;
	int n=length-1;
	for(i=1;i<=n;i++)
		m[i][i]=0;
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=9999;
			for(k=i;k<=j-i;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<=m[i][j])
					m[i][j]=q;
				s[i][j]=k;
			}
		}
	}
}
void print_optimal(int i,int j)
{
	if(i==j)
		printf(" M%d ",i);
	else
	{
		printf("( ");
		print_optimal(i,s[i][j]);
		print_optimal(s[i][j]+1,j);
		printf(" )");
	}
}
main()
{
	int p[]={10,20,50,1,100};
	int length=5;
	matrix_chain_order(p,length);
	print_optimal(1,4);
}
