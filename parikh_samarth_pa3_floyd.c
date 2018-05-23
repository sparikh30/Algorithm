#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int v,c[100][100], p[100][100];  //declare cost matrix and path matrix to maximum size
								 // V is number of vertices
void path(int x, int y);		 // declare the path method which prints the path

void display();

int main()
{
	 int i, j, k;
     
     srand (time(NULL));
	 
	 v=5+rand()%5;

 	 printf("number of vertices in the graph: %d\n",v);
 	 
  	 for(i=1;i<=v;i++)				// run loop for v nodes
	 {
  		for(j=1;j<=i;j++)			// generate numbers for lower matrix only
		{
			if(i==j)
			{
				c[i][j]=0;			// diagonal values will be same
			}
			else
			{
				c[i][j]=1+rand()%10;	// random number between 1 to 10
				c[j][i]=c[i][j];
			}
		    p[i][j]=-1;				//assign initial path matrix to -1	
			p[j][i]=-1;
  		}
  	 } 

	printf("\nInitial Matrix C:");	//prints intial Cost matrix
		  	 
  	for(i=1;i<=v;i++)
	{
	 	printf("\n");
  		for(j=1;j<=v;j++)
		{
			printf("\t%d",c[i][j]);
		}
	}
	
	
	printf("\n\nInitial Matrix P:\n");	//prints initial path matrix
	
	for(i=1;i<=v;i++)
	{
		printf("\n");
  		for(j=1;j<=v;j++)
		{
		   printf("\t%d", p[i][j]);
  		}
  	 }
  	 
	 printf("\n");

	 for(k=1;k<=v;k++)					// checks for shortest path through each node k
	 {
		  for(i=1;i<=v;i++)				//source vertices
		  {
			   for(j=1;j<=v;j++)		//destination vertices
			   {
				    if(i==j)
		    			 c[i][j]=0;
				    else
	    			{
	    				 if(c[i][j]>(c[i][k]+c[k][j]))	// path from other vertices is shorter ?
					     {
	      					c[i][j]=c[i][k]+c[k][j];	// assigns shorter cost to cost matrix		
   							p[i][j]=k;					// save : through which vertices the path goes
   						 }
	    			}
	   			}
		   }	
	}
		 
		 
	printf("\nFinal matrix c:\n");		// prints final cost matrix
	
	for(i=1;i<=v;i++)
	{
	 	printf("\n");
  		for(j=1;j<=v;j++)
		{
			printf("\t%d",c[i][j]);
		}
	}
	
	
	printf("\n\nFinal matrix P:\n");		// prints final path matrix
	
	for(i=1;i<=v;i++)
	{
	 	printf("\n");
		for(j=1;j<=v;j++)
		{
			printf("\t%d",p[i][j]);
		}
	}

	display();								// display path from all the node to all other nodes
	
 	return 0;
}

void display()
{
	int i,j;
	printf("\n\nSource\tDest\tPath\t\tlength\n");

	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			if(i!=j)
			{
				printf("%d\t", i);		// source vertices
			    printf("%d\t", j);		//destination vertices
		    	printf("v%d", i);		
		    	path(i,j);				// calls path function to print the whole path
		    	printf("%d\t", j);		
    			printf("\t%d", c[i][j]);	// prints total cost
		    	printf("\n");
	   		}
	  	}
	}
}

void path(int i, int j) //prints the whole path
{
	int m;
	m=p[i][j];
	if(m==-1)
	{
		printf("->v");
		return;
	}
	path(i,m);		//recursive call till destination vertices
	printf("%d",m);
	path(m,j);
}
