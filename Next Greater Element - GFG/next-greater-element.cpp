//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        stack<long long>s;
        vector<long long>vec;
        for(int i=n-1;i>=0;i--){
            while(!s.empty()){
                if(s.top()>arr[i]){vec.push_back(s.top());break;}
                else s.pop();
            }
            if(s.empty())vec.push_back(-1);
            s.push(arr[i]);
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends