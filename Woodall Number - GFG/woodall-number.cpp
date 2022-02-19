// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isWoodall(int N){
        // code here
        int i=1;N=N+1;
        while(i<20){
            if(i*(pow(2,i))==N)return 1;
            i++;
        }return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.isWoodall(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends