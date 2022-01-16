// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void printArr(int arr[],int n)
    {
        //Your code for printing array here
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    void setToZero(int arr[],int n)
    {
       //Use memset to set arr to zero
       memset(arr, 0, 4*n);
    
    }
    
    void xor1ToN(int arr[], int n)
    {
       //Xor arr[i]^i
        for(int i=0;i<n;i++){
            arr[i]=arr[i]^i;
        } 
       
    }
};


// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    Solution obj;
	    obj.xor1ToN(arr,n);
	    obj.printArr(arr,n);
	    obj.setToZero(arr,n);
	    obj.printArr(arr,n);
	}
	return 0;
}

  // } Driver Code Ends