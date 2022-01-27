// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    bool checkIsAP(int arr[], int n)
    {
        // code here
        sort(arr,arr+n);
        if(n==2)return 1;
        for(int i=2;i<n;i++){
            if((arr[i]-arr[i-1])!=(arr[i-1]-arr[i-2]))return 0;
        }return 1;
        
    }

};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
         (ob.checkIsAP(arr, n))? (cout << "YES" << endl) :
                       (cout << "NO" << endl);   
    }
 
  return 0;
}
  // } Driver Code Ends