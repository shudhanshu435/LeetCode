// { Driver Code Starts
//Initial Template for C++

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

// User function Template for C++
class Solution {
  public:
    long double NthTerm(int N){
        // code here
        if(N&1)return pow(2,pow(2,N/2));
        else return pow(2,pow(3,(N/2)-1));
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout<< fixed << setprecision(0)<<ob.NthTerm(N)<<endl;
    }
    return 0;
}
  // } Driver Code Ends