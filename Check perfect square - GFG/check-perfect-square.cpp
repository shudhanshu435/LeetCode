// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int checkPerfectSquare(int N){
        // code here 
        for(int i=0;i<1000;i++){
            if(i*i==N)return 1;
            if(i*i>N)return 0;
        }
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.checkPerfectSquare(N) << endl;
    }
    return 0; 
}   // } Driver Code Ends