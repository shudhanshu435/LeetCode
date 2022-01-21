// { Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    string isPart(int n) { 
        //complete the function here
        int cnt=0;
        for(int i=2;i<n+2;i++){
            if((n+2)%i==0){cnt++;break;}
        }
        if(cnt==0)return "Yes";
        else return "No";
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
        cin >> n;
        Solution ob;
        cout << ob.isPart(n) << endl;
    
    }
    return 0; 
} 
  // } Driver Code Ends