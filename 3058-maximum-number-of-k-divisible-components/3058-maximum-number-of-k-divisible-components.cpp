class Solution {
public:
    long long dfs(int node, int parent, int &ans, vector<vector<int>>&adj, vector<int>&values, int &k){
        long long sum=values[node];
        for(auto it:adj[node]){
            if(it!=parent){
                sum+=dfs(it, node, ans, adj, values, k);
            }
        }
        sum%=k;
        if(sum==0){
            ans++;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans=0;
        dfs(0, -1, ans, adj, values, k);
        return ans;
    }
};