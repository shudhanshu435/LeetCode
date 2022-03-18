// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string S, int R, int N) {
        //code here
        bool flip = false;
  
        while (-- R >= 0)
        {
            flip ^= N & 1;
            N >>= 1;
        }
           
        return S[N] ^ flip;
            }
        };

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}  // } Driver Code Ends