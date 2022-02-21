// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> jugglerSequence(int N){
        // code here
        vector<int>vec;
        vec.push_back(N);
        int m;
        while(N!=1){
            if(N&1){
                m=pow(sqrt(N),3);
                vec.push_back(m);
                N=m;
            }else{
            m=sqrt(N);
            vec.push_back(m);
            N=m;
            }
        }
        return vec;
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
        vector<int> ans = ob.jugglerSequence(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends