class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        queue<tuple<int,int,int>>q;
        if(grid[0][0]==1)q.push({0,0,1});
        else q.push({0,0,0});
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        dp[0][0]=0;
        while(!q.empty()){
            auto [i,j,k]=q.front();
            q.pop();
            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};
            for(int d=0;d<4;d++){
                int ni=i+dx[d];
                int nj=j+dy[d];
                if(ni>=0 and nj>=0 and ni<m and nj<n and k+grid[ni][nj]<dp[ni][nj]){
                    dp[ni][nj]=k+grid[ni][nj];
                    q.push({ni,nj,dp[ni][nj]});
                }
            }

        }
        if(dp[m-1][n-1]<health)return 1;
        return 0;
    }
};