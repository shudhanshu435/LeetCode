// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> nearestPerfectSquare(int N) {
        // code here
        vector<int>vec;
        int n=(int)sqrt(N);
        int m=((N-(n*n))>((n+1)*(n+1)-N))?(n+1)*(n+1):(n*n);
        vec.push_back(m);
        vec.push_back(abs(m-N));
        return vec;
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
        vector<int> ans = ob.nearestPerfectSquare(N);
        cout << ans[0] << " " << ans[1] << "\n";
    }
}  // } Driver Code Ends