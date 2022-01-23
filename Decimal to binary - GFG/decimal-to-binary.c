// { Driver Code Starts
//Initial Template for C


#include <stdio.h>

 // } Driver Code Ends
//User function Template for C

void toBinary(int N)
{
    // your code here
    int arr[100],cnt=0;
    for(int i=0;N!=0;i++){
        arr[i]=N&1;
        cnt++;
        N>>=1;
    }
    for(int i=cnt-1;i>=0;i--){
        printf("%d",arr[i]);
    }
        
}

// { Driver Code Starts.

int main() {
	//code
	
	int t;
	scanf("%d", &t);
	
	
	while(t--)
	{
	    int n;
	    scanf("%d", &n);
	    
	    toBinary(n);
	    printf("\n");
	}
	return 0;
}  // } Driver Code Ends