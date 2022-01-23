// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        vector<long long>vec;
        long long int gcdd=gcd(A,B);
        long long int lcm=(A*B)/gcdd;
        vec.push_back(lcm);
        vec.push_back(gcdd);
        return vec;
    }
    long long int gcd(long long int a,long long int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends