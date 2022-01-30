// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    long long int squaresDiff(int N){
        // code here
        long long int sum1=0,sum2=0;
        for(int i=1;i<=N;i++){
            sum1+=i;
            sum2+=(i*i);
        }
        return abs((sum1*sum1)-sum2);
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
        cout << ob.squaresDiff(N) << endl;
    }
    return 0;
}
  // } Driver Code Ends