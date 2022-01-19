// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]<0)cnt++;
        }if(cnt==n){
            sort(arr,arr+n);
            return arr[n-1];
        }
        else{
        long long int ss=0,kk=0;
        for(int i=0;i<n;i++){
            ss+=arr[i];
            kk=(ss>kk)?ss:kk;
            if(ss<0)ss=0;
        }
        return kk;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends