class Solution {
public:
    int ans=INT_MAX;
    void dfs(int u, unordered_map<int,vector<pair<int,int>>>&mp, vector<bool>&vis){
        vis[u]=1;
        for(auto i:mp[u]){
            int f=i.first;
            ans=min(ans,i.second);
            if(!vis[f]){
                dfs(f,mp,vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto &i:roads){
            int u=i[0];
            int v=i[1];
            int w=i[2];
            mp[u].push_back({v,w});
            mp[v].push_back({u,w});
        }
        vector<bool>vis(n,0);
        dfs(1,mp,vis);
        return ans;
    }
};