#include<stdio.h>
#include<string.h>
int next[100];
void compute_next(char p[],int m[])
{
	int i,j;
	next[1]=-1;
	next[2]=0;
	for(i=3;i<m;i++)
	{
		j=next[i-1]+1;
		while((p[i-1]!=p[j]) && (j>0))
			j=next[j]+1;
		next[i]=j;
	}
}
void kmp(char t[],char p[],int m,int n)
{
	int shift=0,j=1,i=1;
	while(i<=n)
	{
		if(p[j]==t[i])
		{
			i=i+1;
			j=j+1;
		}
		else
		{
			j=next[j]+1;
			if(j==0)
			{
				j=1;
				i=i+1;
			}
		}
		if(j==m+1)
		{
			printf("Match occured at:%d",i-m);
			shift=(i-m);
			j=1;
			i=i+1;
		}
	}
}
main()
{
	char t[100],p[50];
	puts("Enter the text string:");
	gets(t);
	puts("Enter the pattern string:");
	gets(p);
	puts(p);
	int m=strlen(p);
	int n=strlen(t);
	compute_next(p,m);
	kmp(t,p,m,n);
}
