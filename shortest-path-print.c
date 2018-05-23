#include<stdlib.h>
#include<stdio.h>

int c[100][100], p[100][100];  //c-cost matrix, p-path matrix(to store the path)

int inf=1000, v;     //Assume Infinity as 1000

//int min(int x, int y);

void show();

void path(int, int);

int main()
{

	 int i, j, k, x;

 	 printf("Enter the number of vertices in the graph: ");

	 scanf("%d", &v);

	 printf("\nEnter adjacency matrix:\n");

	 printf("(Enter 1000 if there is no path)\n");

  	 for(i=1;i<=v;i++)
	 {
  		for(j=1;j<=v;j++)
		{
		   scanf("%d", &c[i][j]);
		   p[i][j]=-1;
  		}
  	 } 
		 printf("\n");

		 for(k=1;k<=v;k++)
		 {
			  for(i=1;i<=v;i++)
			  {
				   for(j=1;j<=v;j++)
				   {
					    if(i==j)
		    			 c[i][j]=0;
					    else
		    			{
		    				 x=c[i][k]+c[k][j];
		    				 if(c[i][j]>x)
						     {
		      					c[i][j]=x;
      							p[i][j]=k;
     						 }
		    			}
		   			}
  			   }	
			   printf("\n");
		 }
		 
		 
  	 printf("\n\n");		 
for(i=1;i<=v;i++)
	 {
	 printf("\n");
  		for(j=1;j<=v;j++)
		{
		   printf("\t%d", p[i][j]);
  		}
  	 }
  	 printf("\n\n");
 		printf("From\tTo\tPath\t\tTotal Min. Cost\n");


  	 
  	 
	 for(i=1;i<=v;i++)
	 {
	  for(j=1;j<=v;j++)
	  {
	   if(i!=j)
	   {
	    printf("%d\t", i);
	    printf("%d\t", j);

    	printf("%d", i);

    	path(i,j);

    	printf("%d", j);



    	printf("\t\t%d", c[i][j]);
	
    	printf("\n");

	   }
	
	  }
	
	 }

 return 0;

}


//-------TO SHOW THE PATH-------	

void path(int i, int j)
{
 	int k;

	 k=p[i][j];

	 if(k==-1)
	 {
		  printf("->");
		  return;
	 }
	 path(i, k);
	 printf("%d",k);
	 path(k,j);
}

