class Solution {
public:
    void bfs(queue<pair<int,int>>&q, vector<vector<int>>&h, vector<vector<bool>>&vis){
        int m=h.size(),n=h[0].size();
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(auto [dr,dc]:dir){
                int nr=r+dr;
                int nc=c+dc;
                if(nr<0 or nr>=m or nc<0 or nc>=n)continue;
                if(vis[nr][nc])continue;
                if(h[nr][nc]<h[r][c])continue;
                vis[nr][nc]=1;
                q.push({nr,nc});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<bool>>pac(m,vector<bool>(n,0));
        vector<vector<bool>>atl(m,vector<bool>(n,0));
        queue<pair<int,int>>qp,qa;
        for(int i=0;i<m;i++){
            pac[i][0]=1;
            qp.push({i,0});
        }
        for(int j=0;j<n;j++){
            pac[0][j]=1;
            qp.push({0,j});
        }

        for(int i=0;i<m;i++){
            atl[i][n-1]=1;
            qa.push({i,n-1});
        }
        for(int j=0;j<n;j++){
            atl[m-1][j]=1;
            qa.push({m-1,j});
        }

        bfs(qp, heights, pac);
        bfs(qa, heights, atl);

        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] and atl[i][j])ans.push_back({i,j});
            }
        }
        return ans;

    }
};