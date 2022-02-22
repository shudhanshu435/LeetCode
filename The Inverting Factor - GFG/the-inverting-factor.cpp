// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find the minimum inverting factor 
int findMinimumInvertingFactor(int arr[], int N);

int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        cout << findMinimumInvertingFactor(arr, n);
        
        cout << endl;
        
    }

}

// } Driver Code Ends


int findMinimumInvertingFactor(int arr[], int N) 
{ 
    // Complete the function 
    for(int i=0;i<N;i++){
        int m=arr[i],x=0;
        while(m){
            int t=m%10;
            x=(x*10)+t;
            m/=10;
        }
        arr[i]=x;
    }
    
    int min=abs(arr[0]-arr[1]);
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(abs(arr[i]-arr[j])<=min){
                min=abs(arr[i]-arr[j]);
            }
        }
    }return min;
} 
