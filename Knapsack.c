#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

#define A 20

// Global variable declaration

float netprofit,netwt;
int w[A],p[A];
int n,m,temp[A],x[A];

 
// Declaring the functions
 
float Bound_find(int aa,int bb,int cc);
void BackTrack(int dd,int ee,int ff);
 
void main()
{
 int i,sum=0;											// sum to add all the weight
 
  srand (time(NULL));
	 
	n=5+rand()%4;
 
 printf("\n number of Objects selected: %d",n);			// number of items randomly assigned
 printf("\n");
 
 for(i=1;i<=n;i++)
 {
 	 p[i]=10+rand()%20;									// profit for each itme				
 	 w[i]=5+rand()%15;									// weight of each itme
 	 sum+=w[i];
 }
 
 m=(0.6*sum);											// weight of knapsack
 
 //m=xx;
 
 printf("\n Capacity of Knapsack: %d",m);


 
 printf("\n Weight\tProfit");
 printf("\n");
 
 for(i=1;i<=n;i++)
 {
  printf("\n %d \t %d",w[i],p[i]); 
 }
 
 printf("\n\n"); 
 BackTrack(1,0,0);										// call the logic function
  
 printf("\n");
 printf("\n Following Objects are included:");
 printf("\n");
 for(i=1;i<=n;i++)
 {
  if(x[i]==1)
   printf("\n%d",i);
 }
 printf("\n-------------------------------------------------------");
 printf("\n Total Weight:%0.2f",netwt);
 printf("\n Total Profit:%0.2f\n",netprofit);	
}

// find the bound of each node----------------------------------------//

float Bound_find(int cur_pro,int cur_wei,int k)
{
 int upper_b,c,i;
 upper_b=cur_pro;
 c=cur_wei;
 for(i=k+1;i<=n;i++)
 {
 	 c=c+w[i];
 	 if(c < m)
 		  upper_b=upper_b+p[i];
 	 else
 		  return (upper_b+(1-(c-m)/w[i])*p[i]);			// Fraction knapsack find bound;
 }
 printf("\n Bound %d ",upper_b);
 return upper_b;
}

// call backtrack recursively to add each node one by one -------------//

void BackTrack(int k,int cur_pro,int cur_wei)			// k is item to add
{
	 int new_k,new_cur_pro,new_cur_wei,j;	

	 if(cur_wei+w[k] <=m)								// current weight + weight og item to add is <= total capacity of sack
	 {
	 
	 	  printf("Profit : %d weight :%d",cur_pro,cur_wei);	
		  temp[k]=1;									// add item to temp
		  if(k < n)										// add each item one by one to sack	
		  {
   			new_k=k+1;
  		 	new_cur_pro=cur_pro+p[k];
 	  	    new_cur_wei=cur_wei+w[k];
		    BackTrack(new_k,new_cur_pro,new_cur_wei);
  		  }
	      if((new_cur_pro>netprofit)&&(k==n))			// for leaf node
		  {
		   printf("Profit : %d weight :%d",cur_pro,cur_wei);	
			   netprofit=new_cur_pro;					// add current temp items to final array if condition is met
			   netwt=new_cur_wei;
			   for(j=1;j<=k;j++)
			   {
				    x[j]=temp[j];
			   }
  		  }
 	 }
  
 	if(Bound_find(cur_pro,cur_wei,k)>=netprofit)		// compare the promising node condition
 	{
 		 temp[k]=0;
  		 if(k < n)										
		   BackTrack(k+1,cur_pro,cur_wei);
		   
  		  if((cur_pro>netprofit)&&(k==n))
		  {
  			 netprofit=cur_pro;							// update the Max profit after each time profit is updated
		     netwt=cur_wei;
		     for(j=1;j<=n;j++)
			    x[j]=temp[j];
  		  }
 	}
}
