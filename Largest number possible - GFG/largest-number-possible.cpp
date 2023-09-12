//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        
        string s="";
        if(N==1 && S==0)return "0";
        if(N*9<S || S==0)return "-1";
        for(int i=0;i<N;i++){
            if(S==0)s+='0';
            else if(S>9){s+='9';S=S-9;}
            else {
                s+=(char)(S+48);
                S=0;
            }
        }
        return s;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends