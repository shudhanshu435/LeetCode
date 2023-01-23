//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        vector<int>vec;
        stack<int>s;
        s.push(-1);
        for(int i=0;i<n;i++){
            if(a[i]>s.top()){
                vec.push_back(s.top());
                s.push(a[i]);
            }
            else{
                while(s.top()>=a[i])s.pop();
                vec.push_back(s.top());
                s.push(a[i]);
            }
        }
        return vec;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends