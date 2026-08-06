class Solution {
public:
    vector<int>vec;
    int ans=0;
    int dfs(int node, int p, vector<vector<int>>&adj){
        vec[node]=1;
        int ex=-1;
        bool b=1;
        for(auto i:adj[node]){
            if(i==p)continue;
            int ss=dfs(i,node,adj);
            if(ex==-1)ex=ss;
            else if(ex!=ss)b=0;

            vec[node]+=ss;
        }
        if(b)ans++;

        return vec[node];
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        vec.resize(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0,-1,adj);
        return ans;
    }
};