//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
        // code here
        vector<int>vec;
        for(int i=0;i<N;i++){
            int req=H[i];
            auto itr=lower_bound(vec.begin(),vec.end(),req);
            if(itr==vec.end())vec.push_back(req);
            else *itr=req;
        }
        return N-vec.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends