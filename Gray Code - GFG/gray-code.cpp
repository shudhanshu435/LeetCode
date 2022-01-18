// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int getGray(int n) {
        // code here
        string s="";
        int sum=0;
        while(n){
            int t=(n&1)^((n>>1)&1);
            s+=t;
            n>>=1;
        }
        for(int i=0;i<s.length();i++){
            if(s[i]==1)sum+=1<<i;
        }
        return sum;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.getGray(n) << endl;
    }
    return 0;
}  // } Driver Code Ends