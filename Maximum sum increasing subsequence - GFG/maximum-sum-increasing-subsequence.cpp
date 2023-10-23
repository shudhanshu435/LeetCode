//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int dp[n];
	    int omax=INT_MIN;
	    for(int i=0;i<n;i++){
	        int max=0;
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i]){
	                if(max==NULL)max=dp[j];
	                else if(dp[j]>max)max=dp[j];
	            }
	        }
	        
	        if(max==0)dp[i]=arr[i];
	        else dp[i]=max+arr[i];
	        
	        if(dp[i]>omax)omax=dp[i];
	    }
	    return omax;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends