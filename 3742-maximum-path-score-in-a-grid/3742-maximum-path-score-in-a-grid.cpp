class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
    
        auto score=[&](int v){return v==2 ? 2 : v;};
        auto cost=[&](int v){return v==0 ? 0 : 1;};
    
        int sc=score(grid[0][0]);
        int cs=cost(grid[0][0]);
        int ans=-1;
        if(cs<=k) dp[0][0][cs]=sc;
    
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int c=0;c<=k;c++){
                    if(dp[i][j][c]<0) continue;
    
                    if(j+1<n){
                        int nc=c+cost(grid[i][j+1]);
                        if(nc<=k) dp[i][j+1][nc]=max(dp[i][j+1][nc],dp[i][j][c]+score(grid[i][j+1]));
                    }
    
                    if(i+1<m){
                        int nc=c+cost(grid[i+1][j]);
                        if(nc<=k) dp[i+1][j][nc]=max(dp[i+1][j][nc],dp[i][j][c]+score(grid[i+1][j]));
                    }
                }
            }
        }
        for(int c=0;c<=k;c++) ans=max(ans,dp[m-1][n-1][c]);
        return ans;
    }
};