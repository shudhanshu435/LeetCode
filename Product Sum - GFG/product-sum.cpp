// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long int countDigits(long long int a, long long int b) { 
        // code here
        long long int cnt=0;
        long long int g= a*b;
        while(g){
            g/=10;
            cnt++;
            
        }
        
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int a,b;
        cin >> a >> b;
        Solution ob;
        cout << ob.countDigits(a, b) << endl;
    }
    return 0;
}
  // } Driver Code Ends