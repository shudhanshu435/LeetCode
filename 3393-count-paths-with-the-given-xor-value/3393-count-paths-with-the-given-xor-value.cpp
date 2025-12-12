class Solution {
public:
int mod=1000000007;
    int countPathsWithXorValue(vector<vector<int>>& grid, int K) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(16,0)));
        dp[0][0][grid[0][0]]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0)continue;
                int v=grid[i][j];
                for(int k=0;k<16;k++){
                    if(i>0)dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k^v])%mod;
                    if(j>0)dp[i][j][k]=(dp[i][j][k]+dp[i][j-1][k^v])%mod;
                }
            }
        }
        return (dp[n-1][m-1][K])%mod;
    }
};