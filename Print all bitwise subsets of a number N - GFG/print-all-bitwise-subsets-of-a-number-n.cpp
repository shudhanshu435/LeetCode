// { Driver Code Starts

// CPP program to print all bitwise
// subsets of N (Efficient approach)

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

// fucntion to find bitwise subsets
// Efficient approach
class Solution {
public:
    vector<int> printSubsets(int n) {
        // Code here
        vector<int>vec;
        for(int i=n;i>=0;i--){
            if((i&n)==i)vec.push_back(i);
        }return vec;
    }
};


// { Driver Code Starts.

int main() { 
    Solution ob;
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> v;
        v = ob.printSubsets(n);
        for(int i: v)
            cout << i << " ";
        cout << endl;
    }

return 0;
}
  // } Driver Code Ends