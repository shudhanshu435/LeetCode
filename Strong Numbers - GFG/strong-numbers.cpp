// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    long long int fact (int n){
        if(n==0 || n==1)return 1;
        return n*fact(n-1);
    }
  
    int isStrong(int N) {
        // code here
        int s=N;
        long long int sum=0;
        while(N){
            int t=N%10;
            sum+=fact(t);
            N/=10;
        }
        if(sum==s)return 1;
        else return 0;
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
        cout << ob.isStrong(N) << endl;
    }
    return 0;
}  // } Driver Code Ends