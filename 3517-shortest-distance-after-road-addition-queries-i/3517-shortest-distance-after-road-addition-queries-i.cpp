class Solution {
public:
    int bfs(vector<vector<int>>& adj, int n){
        queue<int>q;
        q.push(0);
        vector<int>visited(n);
        visited[0]=true;
        int dist=0;

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int curr=q.front();
                q.pop();
                if(curr==n-1)return dist;

                for(int adjc: adj[curr]){
                    if(!visited[adjc]){
                        visited[adjc]=true;
                        q.push(adjc);
                    }
                }
            }
            dist++;
        }
        return dist;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        vector<int>res;
        for(auto& v:queries){
            adj[v[0]].push_back(v[1]);
            res.push_back(bfs(adj,n));
        }
        return res;
    }
};