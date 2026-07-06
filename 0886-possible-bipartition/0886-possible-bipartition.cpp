class Solution {
public:
    bool bfs(vector<vector<int>>& graph, queue<int>&q, vector<int>&vis, vector<int>&col){
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
    bool possibleBipartition(int v, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(v);
        for(auto i:dislikes){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        vector<int>col(v),vis(v,0);
        queue<int>q;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
                if(!bfs(adj,q,vis,col))return 0;
            }
        }
        return 1;
    }
};