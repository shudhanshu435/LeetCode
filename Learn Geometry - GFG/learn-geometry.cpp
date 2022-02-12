// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    long long maxSquares(int B) {
        // code here
        long long int t=(B/2)-1;
        return t*(t+1)/2;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long B;
        
        cin>>B;

        Solution ob;
        cout << ob.maxSquares(B) << endl;
    }
    return 0;
}  // } Driver Code Ends