// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    string jumpingGeek(int N) {
        // code here
        if(N==0||N%3==0)return "yes";
        int i=1;
        while(1){
            if(i==N)return "yes";
            i+=6;
            if(i>N)break;
        }return "no";
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
        cout << ob.jumpingGeek(N) << endl;
    }
    return 0;
}  // } Driver Code Ends