class Solution {
public:
    void dfs(int i, vector<bool>&vis, vector<vector<int>>&vec, vector<int>&vp){
        vis[i]=1;
        vp.push_back(i);
        for(auto ii:vec[i]){
            if(!vis[ii]){
                dfs(ii,vis,vec,vp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>vec(n);
        for(auto i:edges){
            vec[i[0]].push_back(i[1]);
            vec[i[1]].push_back(i[0]);
        }
        vector<bool>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>v;                
                dfs(i,vis,vec,v);
                int ss=v.size();
                bool ok=1;
                for(auto i:v){
                    if(vec[i].size()!=ss-1){
                        ok=0;break;
                    }
                }
                if(ok)cnt++;

            }
        }

        return cnt;

    }
};