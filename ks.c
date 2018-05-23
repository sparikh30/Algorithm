#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void mysack(int n, float sack_wei[], float sack_pro[], float size)
{
   float x[20], yy = 0;
   int i, j, xx=size;
 
   for (i = 0; i < n; i++)						//initializing x array
   {
      x[i] = 0.0;
   }
   
   for (i = 0; i < n; i++) 
   {
      if (sack_wei[i] > xx)						// if the total weight is more then sack weight then break the loop
         break;
      else 
      {
         x[i] = 1.0;
         yy = yy + sack_pro[i];					// add each item one by one reduce the size of sack
         xx = xx - sack_wei[i];         
         printf("\n weight=%d \t profit=%d",(int)sack_wei[i],(int)sack_pro[i]);
      }
   } 
   if (i < n)
      x[i] = xx / sack_wei[i];
   yy = yy + (x[i] * sack_pro[i]);
   printf("\nTotal weight is: %d",(int)size);	  // print the Total weight of sack	
   printf("\nMaximum profit is:- %d\n", (int)yy);	// print the Maximum profit achieved

 
}
 
int main() 
{
   float wei[20], pro[20], size,r[20], temp;
   int num, i, j,sum=0;
 
   srand(time(NULL)); 
   num=5+rand()%4; 												// randomly select the item number					
 
   printf("\nThe no. of objects selected randomly:- %d \n",num); 	
   
   for (i = 0; i < num; i++) 
   {
      wei[i]=5+rand()%15;										// randomly select the weight		
      pro[i]=10+rand()%20;										// randomly select the profit
      sum+=wei[i];	
   }
 
   printf("\nThe wts and profits of each object:- ");
   printf("\nweight\tprofit");
   for (i = 0; i < num; i++) 
   {
      printf("\n%d\t%d", (int)wei[i],(int) pro[i]);
   }
   size=0.6*sum;												// size of the sack	
 	
   printf("\nThe capacity of knapsack:- %d ",(int)size);
   
 
   for (i = 0; i < num; i++) 
   {
      r[i] = pro[i] / wei[i];									// storing Pi/Wi into r array
   }
   for (i = 0; i < num; i++) 
   {
      for (j = i + 1; j < num; j++) 		
      {
         	if (r[i]<r[j]) 
         	{
	            temp = r[j];								// sorting the values in order for r
	            r[j] = r[i];
	            r[i] = temp;
 
	            temp = wei[j];			// sorting the values in order for weight array
	            wei[j] = wei[i];
	            wei[i] = temp;
 
	            temp = pro[j];			// sorting the values in order for profit array
	            pro[j] = pro[i];
	            pro[i] = temp;
         	}
      }
   }
   mysack(num, wei, pro, size);				// call to the logic function
   return(0);
}
