// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

 // } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    // Your code goes here
    long long p=0,q=len-1;
    long long m,maxi=0;
    while(p<q){
        m=min(A[p],A[q]);
        long long area=m*(q-p);
        maxi=max(area,maxi);
        if(A[p]<A[q])p++;
        else q--;
    }return maxi;
}

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}
  // } Driver Code Ends