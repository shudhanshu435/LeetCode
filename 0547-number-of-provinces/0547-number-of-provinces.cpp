class Solution {
public:
    void dfs(int u, vector<vector<int>>& con, vector<bool>&vis){
        vis[u]=1;
        for(int i=0;i<con.size();i++){
            if(con[u][i]==1 and !vis[i]){
                dfs(i,con,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>vis(n,0);
        int k=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                k++;
            }
        }
        
        return k;
    }
};