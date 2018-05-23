#include <iostream>
#include<stdio.h>
using namespace std;
int n,W,wt[10],val[10],k[200][200];
 
// A utility function that returns maximum of two integers

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int ksrecursive(int k[200][200],int m,int s)
{
	if(m==1 | s<=0)	
	{
		if(wt[m-1]<=s)
		return	 max(k[m-1][s],val[m-1]+k[m-1][s-wt[m-1]]);		
		else
		return k[m-1][s];
	}
	else
	{	
		if(wt[m-1]<=s)
		{
		k[m-1][s]=ksrecursive(k,m-1,s);
		k[m-1][s-wt[m-1]]= ksrecursive(k,m-1,s-wt[m-1]);	
		return max(k[m-1][s],k[m-1][s-wt[m-1]] + val[m-1]);
		}
		else
		k[m-1][s]=ksrecursive(k,m-1,s);
		return k[m-1][s];	
	}						
}


int knapSack()
{
    int i,j;

    for (i = 0; i <= 200; i++)
    {
        for ( j = 0; j <= 200; j++)
        {
            if (i == 0 || j == 0)
                k[i][j] = 0;       
 	    }
    }
    k[n][W]= ksrecursive(k,n,W);
    
	int y=W;
    W=0; 
  	for(int q=n,r=y;q>0;q--)
  	{
  		if((k[q][r]- k[q-1][r-wt[q-1]])==val[q-1])
  		{
  			printf("\n item %d is in knapsack with weight %d ",q,wt[q-1]);
  			r=r-wt[q-1];		
  			W=W+wt[q-1];
  		}
  	}  
    
    return k[n][y];
}

int main()
{
    cout << "Enter the number of items in a Knapsack:";

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value and weight for item " << i << ":";
        cin >> val[i];
        cin >> wt[i];
    }

    cout << "Enter the capacity of knapsack";
    cin >> W;
    cout <<endl<<"Maximum profit for knapsack :" <<knapSack()<< "\t"<<"Total Weight :"<< W   <<endl;
    return 0;
}
