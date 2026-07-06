class Solution {
public:
    bool bfs(int u, vector<vector<int>>& graph, queue<int>&q, vector<int>&vis, vector<int>&col){
        vis[u]=1;
        while(!q.empty()){
            int node=q.front();
            int v=col[node];
            q.pop();
            for(auto i:graph[node]){
                if(!vis[i]){
                    q.push(i);
                    col[i]=v^1;
                    vis[i]=1;
                }
                else{
                    if(col[i]==v)return 0;
                }
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>col(v),vis(v,0);
        queue<int>q;
        q.push(0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                q.push(i);
                if(!bfs(i,graph,q,vis,col))return 0;
            }
        }
        return 1;
    }
};