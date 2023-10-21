//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void genCom(int ind, vector<int> &cand, int tar, vector<int> &v, vector<vector<int>>&vec){
        if(tar==0){
            vec.push_back(v);
            return;
        }
        for(int i=ind;i<cand.size();i++){
            if(i>ind && cand[i]==cand[i-1])continue;
            if(cand[i]>tar)return;
            v.push_back(cand[i]);
            genCom(i+1,cand,tar-cand[i],v,vec);
            v.pop_back();
        }
    }
  public:
    vector<vector<int>> combinationSum2(vector<int> &cand, int tar) {
        // Write your code here
        vector<vector<int>>vec;
        sort(cand.begin(),cand.end());
        vector<int>v;
        genCom(0,cand,tar,v,vec);
        return vec;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends