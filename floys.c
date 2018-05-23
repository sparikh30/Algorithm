#include<stdio.h>
#define size 10/*Defining maximum size of the weight-matrix*/

void main()
{
	int a[size][size],p[size][size];
	int i,j,n;
	void floyd(int[][j],int);/*Function declaration*/
	
	printf("Enter no. of vertices : ");/*No. of vertex should be less equal to defined size*/
	scanf("%d",&n);
	printf("Give the initial weighted graph in weight matrix form(give 9999 in the place of infinity) : n");
	
	for(i=0;i<n;i++)
	{
			for(j=0;j<n;j++)
			{
			printf("Enter the value of a[%d][%d]:",i,j);/*Giving inputs one by one row-wise,give a 9999 as infinity*/
			scanf("%d",&a[i][j]);
			p[i][j]=-1;
			}
	}

	printf("The input weight matrix is:\n");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==9999)
			printf("inft");/*Printing inf as infinity in the input matrix*/
			else
			printf("%d\t",a[i][j]);/*If data is not infinity then print the weight*/
		}
		printf("\n");
	}
	
	floyd(a,n);/*Function call*/
	printf("nThe final matrix where we can find the shortest distance:n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%5d",a[i][j]);
		printf("\n");
	}
}
	void floyd(int a[size][size],int n)/*Function definition*/
	{
		int k,i,j;
		for(k=0;k<n;k++)/*n is the no.of vertices of the graph and k represents table no.*/
		{
			for(i=0;i<n;i++)/*i represents row no. within a table*/
			{
				for(j=0;j<n;j++)/*j represents column no. within a row*/
				{
					if(a[i][j]>(a[i][k]+a[k][j]))/*Minimum is to be selected*/
					/*a[i][j] denotes distance between ith vertex and jth vertex*/
					a[i][j]=(a[i][k]+a[k][j]);
				}
			}
		}
	}
		 	
