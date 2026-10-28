class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        const int maxi=1024;
        vector<vector<vector<bool>>>dp(m,vector<vector<bool>>(n,vector<bool>(maxi,0)));
        dp[0][0][grid[0][0]]=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 and j==0)continue;
                for(int x=0;x<maxi;x++){
                    if(i>0 and dp[i-1][j][x])dp[i][j][x^grid[i][j]]=1;
                    if(j>0 and dp[i][j-1][x])dp[i][j][x^grid[i][j]]=1;
                }
            }
        }
        for(int x=0;x<maxi;x++){
            if(dp[m-1][n-1][x])return x;
        }

        return -1;
    }
};