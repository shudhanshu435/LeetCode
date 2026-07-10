class Solution {
public:
    void dfs(int &c, int u, unordered_map<int,vector<int>>&mp, vector<bool>&vis){
        vis[u]=1;
        for(auto i:mp[u]){
            if(!vis[i]){
                c+=1;
                dfs(c, i,mp,vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,vector<int>>mp;
        int n=stones.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1]){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<bool>vis(n,0);
        for(int i=0;i<n;i++){
            int c=1;
            if(!vis[i]){
                dfs(c,i,mp,vis);
                // cout<<c<<endl;
                ans+=c-1;
            }
        }
        return ans;
    }
};