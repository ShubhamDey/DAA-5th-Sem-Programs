#include<stdio.h>
#include<stdlib.h>
void floyd(int **d,int n)
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(d[i][j]>d[i][k]+d[k][j])
					d[i][j]=d[i][k]+d[k][j];
			}
		}
	}
}
void main(int argc, char **argv)
{
	int i,n,**mat,j;
	FILE *fp;
	if(argc!=2)
	{
		printf("Instruction incomplete");
		exit(0);
	}
	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		printf("File doesn't exists");
		exit(0);
	}
	fscanf(fp,"%d",&n);
	mat=(int **)calloc(sizeof(int *),n);
	for(i=0;i<n;i++)
		*(mat+i)=(int *)calloc(sizeof(int ),n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		fscanf(fp,"%d",&mat[i][j]);
	}
	floyd(mat,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}
}
