// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    int difProblem(string N) {
        // code here
        if(N.length()==1||N.length()==2)return 1;
        for(int i=1;i<N.length()-1;i++){
            if((N[i]>N[i-1] && N[i]>N[i+1])||(N[i]<N[i-1] && N[i]<N[i+1]))return 0;
        }return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string N;
        
        cin>>N;

        Solution ob;
        cout << ob.difProblem(N) << endl;
    }
    return 0;
}  // } Driver Code Ends