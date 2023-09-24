//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        priority_queue<pair<int,pair<int,int>>>heap;
        heap.push({A[N-1]+B[N-1],{N-1,N-1}});
        
        set<pair<int,int>>mset;
        mset.insert({N-1,N-1});
        
        vector<int>res;
        
        while(K>0){
            pair<int,pair<int,int>> top = heap.top();
            heap.pop();
            
            int sum=top.first;
            int x=top.second.first;
            int y=top.second.second;
            
            res.push_back(sum);
            
            if(mset.find({x-1,y})==mset.end()){
                heap.push({A[x-1] + B[y], {x-1,y}});
                mset.insert({x-1,y});
            }
            if(mset.find({x,y-1})==mset.end()){
                heap.push({A[x] + B[y-1], {x,y-1}});
                mset.insert({x,y-1});
            }
            K-=1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends