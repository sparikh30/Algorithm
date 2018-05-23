#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

using namespace std;
int n,W,wei[10],pro[10],k[200][200];
 
// A utility function that returns maximum of two integers

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int ksrecursive(int k[200][200],int m,int s)
{
	if(m==1 | s<=0)						//	for the first row of the K matrix is base condition
	{
		if(wei[m-1]<=s)
		return	 max(k[m-1][s],pro[m-1]+k[m-1][s-wei[m-1]]);		// we have value for first row and column
		else
		return k[m-1][s];
	}
	else
	{	
		if(wei[m-1]<=s)	
		{
		k[m-1][s]=ksrecursive(k,m-1,s);							// recursive call to function to Find the K[last][last]		
		k[m-1][s-wei[m-1]]= ksrecursive(k,m-1,s-wei[m-1]);	
		return max(k[m-1][s],k[m-1][s-wei[m-1]] + pro[m-1]);
		}
		else
		k[m-1][s]=ksrecursive(k,m-1,s);
		return k[m-1][s];	
	}						
}

// logic function.calls to ksrecursive ----------------------------------------------------------------------------//

int knapSack()																					
{
    int i,j;

    for (i = 0; i <= 200; i++)
    {
        for ( j = 0; j <= 200; j++)
        {
            if (i == 0 || j == 0)			// assigns initial value of K Matrix's first row and first column to zero
                k[i][j] = 0;       
 	    }
    }
    k[n][W]= ksrecursive(k,n,W);			// call to logic funtion
    
	int y=W;
    W=0; 
  	for(int q=n,r=y;q>0;q--)				// logic for retrieving the items that are in sack from K matrix
  	{
  		if((k[q][r]- k[q-1][r-wei[q-1]])==pro[q-1])
  		{
  			printf("\n item %d is in knapsack with weight %d ",q,wei[q-1]);
  			r=r-wei[q-1];		
  			W=W+wei[q-1];
  		}
  	}  
    printf("\n----------------------------------------------------------------------------");
    return k[n][y];
}

int main()
{
	int sum=0;
	
    srand(time(NULL));
	 
	n=5+rand()%4;
   
    cout << "The number of items in a Knapsack: "<<n<<endl;

   

    for (int i = 0; i < n; i++)
    {
    
    	pro[i]=10+rand()%20;									// profit for each itme				
 	 	wei[i]=5+rand()%15;									// weight of each itme
 	 	sum+=wei[i];
    
     }
	W=0.6*sum;
    cout << "The capacity of knapsack :"<<W<<endl;
 	cout<<endl<<"------------------------------------------------------------------" ; 
    cout <<endl<<"Maximum profit for knapsack :" <<knapSack()<< "\t"<<"Total Weight :"<< W   <<endl;
    return 0;
}
