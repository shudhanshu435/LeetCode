// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int nthCarol(int N) {
        // code here
        N=N-1;
        int result=(4<<(N*2))-(2<<(N+1))-1;
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.nthCarol(N) << endl;
    }
    return 0;
}  // } Driver Code Ends