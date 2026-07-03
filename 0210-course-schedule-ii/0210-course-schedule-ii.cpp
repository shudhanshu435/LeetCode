class Solution {
public:
    bool dfs(int u, vector<vector<int>>&adj, vector<int>&vis, vector<int>&path, stack<int>&s){
        vis[u]=1;
        path[u]=1;
        for(auto i:adj[u]){
            if(!vis[i]){
                if(dfs(i,adj,vis,path,s))return 1;
            }
            else if(path[i])return 1;
        }
        path[u]=0;
        s.push(u);
        return 0;
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        stack<int>s;
        vector<int>vis(n,0),path(n,0);
        vector<vector<int>>adj(n);
        for(auto i:pre){
            int u=i[0];
            int v=i[1];
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(!vis[i])if(dfs(i,adj,vis,path,s))return {};
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
        
    }
};