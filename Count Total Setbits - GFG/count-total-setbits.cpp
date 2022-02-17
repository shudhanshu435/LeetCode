// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


class Solution
{
public:
  int largest(int n)
  {
    int x = 0;
    while ((1 << x) <= n)
        x++;
    return x - 1;
  }
 
  int countBits(int N)
  {
    if (N <= 1)
        return N;
    int m = largest(N);
    return (m * pow(2, (m - 1))) + (N - pow(2, m) + 1) + countBits(N - pow(2, m));
  }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.countBits(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends