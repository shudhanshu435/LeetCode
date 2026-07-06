class Solution {
public:
    bool dfs(int u, int p, vector<bool>&vis, vector<vector<int>>&vec){
        vis[u]=1;
        for(auto i:vec[u]){
            if(!vis[i]){
                if(dfs(i,u,vis,vec))return 1;
            }
            else if(p!=i)return 1;
        }
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int v=edges.size();
        for(int i=v-1;i>=0;i--){
            vector<vector<int>>vec(v);
            for(int j=0;j<v;j++){
                if(j==i)continue;
                vec[edges[j][0]-1].push_back(edges[j][1]-1);
                vec[edges[j][1]-1].push_back(edges[j][0]-1);
            }
            vector<bool>vis(v,0);
            bool b=1;
            if(!dfs(0,-1,vis,vec)){
                for(auto i:vis)if(i==0)b=0;
                if(b) return {edges[i][0],edges[i][1]};
            }
        }
        return {};
    }
};