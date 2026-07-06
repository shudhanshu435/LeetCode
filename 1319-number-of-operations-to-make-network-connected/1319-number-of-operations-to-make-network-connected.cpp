class Solution {
public:
    void dfs(int u, vector<vector<int>>&adj, vector<bool>&vis){
        vis[u]=1;
        for(auto i:adj[u]){
            if(!vis[i])dfs(i,adj,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& cc) {
        int m=cc.size();
        if(m<n-1)return -1;
        vector<bool>vis(n);
        vector<vector<int>>adj(n);
        for(auto i:cc){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt-1;
    }
};