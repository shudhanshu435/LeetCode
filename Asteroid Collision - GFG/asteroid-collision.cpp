//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        vector<int>s;
        for(auto x: asteroids){
            if(x>0)s.push_back(x);
            else{
                while(s.size()>0 && s.back()>0 && s.back()<-x)s.pop_back();
                if(s.size()>0 && s.back()==-x)s.pop_back();
                else if(s.size()>0 && s.back()>-x){}
                else s.push_back(x);
            }
        }

        return s;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends