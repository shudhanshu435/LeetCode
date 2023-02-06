//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        sort(arr,arr+n);
        vector<int>vec;
        for(int i=0;i<n;i++)if(arr[i]>0)vec.push_back(arr[i]);
        if(vec.size()==0)return 1;
        if(vec.size()==1&&vec[0]!=1)return 1;
        else if(vec.size()==1&&vec[0]==1) return 2;
        int ans=vec[vec.size()-1]+1;
        if(vec[0]!=1)return 1;
        for(int i=1;i<vec.size();i++){
            if(vec[i]-vec[i-1]>1){
                ans=vec[i-1]+1;
                break;
            }
        }
        return ans;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends