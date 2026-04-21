class Solution {
public:
    void dfs(int node,vector<vector<int>>& graph,vector<int>& vis,
vector<int>& comp){
    vis[node]=1;
    comp.push_back(node);
    for(int ni:graph[node]){
        if(!vis[ni]){
            dfs(ni,graph, vis, comp);
        }
    }
}
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& all) {
        int n=source.size();
        vector<vector<int>>graph(n);
        for(auto &e:all){
            int u=e[0];
            int v=e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int>vis(n,0);

        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>comp;
                dfs(i,graph,vis,comp);

                unordered_map<int,int>freq;

                for(int idx:comp){
                    freq[source[idx]]++;
                }

                for(int idx:comp){
                    if(freq[target[idx]]>0){
                        freq[target[idx]]--;
                    }
                    else ans++;
                }
            }
        }
        return ans;
    }
};