#include<stdio.h>
#include<string.h>
 
int i,j,m,n,c[100][100];
char x[100],y[100],b[100][100];

void print(int i,int j)		//recursive call to function to print the sequence
{
	if(i==0 || j==0)		// if the length is zero
		return;								
	
	if(b[i][j]=='d')		// if d is found then print value dialgonally ie. i-1,j-1
    {
    	print(i-1,j-1);
    	printf("%c",x[i-1]);	
    }
    else if(b[i][j]=='u')	// if u is found then print values upward ie. i-1 row
    	print(i-1,j);		
    else
    	print(i,j-1);		// if l if found then print values of left ie. j-1 column
}

int main(int argc,char *args[])
{	
	if(argc==2)						// if number of command line arguments passed is 2 then string 2 is null
	{	
		strcpy(x,args[1]);
		strcpy(y,"null");
	}
	else if(argc==3)				// if number of arguments are three, both string are copied to x and y
	{
		strcpy(x,args[1]);
		strcpy(y,args[2]);
	}
	else							// if no arguments are passed then both string is assigned null
    {
    	strcpy(y,"null");
    	strcpy(x,"null");
    }
 
    printf("String 1:%s",x);		// print both the string
    printf("\nString 2:%s",y);
    
    m=strlen(x);
	n=strlen(y);
  				                          
    printf("\nLongest Common Subsequence:");
                
    for(i=0;i<=m;i++)		// intialize the matrix with zero
    {
	    c[i][0]=0;
	}
    for(i=0;i<=n;i++)
    {
    	c[0][i]=0;
    }

    for(i=1;i<=m;i++)
    {
    	for(j=1;j<=n;j++)
        {
	        if(x[i-1]==y[j-1])			// move diagonal
            {
            	c[i][j]=c[i-1][j-1]+1;
                b[i][j]='d';
            }
            else if(c[i-1][j]>=c[i][j-1])	// move up
            {
	            c[i][j]=c[i-1][j];
				b[i][j]='u';
			}
			else						// move left
            {
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
	}	
    
    print(m,n);
    printf("\n");
    return 0;
}
