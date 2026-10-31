class Solution {
public:
    int mod=1000000007;
    int solve(vector<vector<vector<int>>>&dp, int i, int j, int prev, vector<vector<int>>&grid){
        if(i==grid.size() or j==grid[0].size())return 0;
        if(i==grid.size()-1 and j==grid[0].size()-1)return 1;
        if(dp[i][j][prev+1]!=-1)return dp[i][j][prev+1];
        int right=0,down=0;
        if(grid[i][j]==1){
            if(prev==0)down=solve(dp,i+1,j,1,grid);
            else right=solve(dp,i,j+1,0,grid);
        }
        else{
            down=solve(dp,i+1,j,1,grid);
            right=solve(dp,i,j+1,0,grid);
        }
        return dp[i][j][prev+1]=(right+down)%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,-1)));
        return solve(dp,0,0,-1,grid);

    }
};