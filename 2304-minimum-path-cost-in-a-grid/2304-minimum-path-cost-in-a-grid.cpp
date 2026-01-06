class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++)dp[0][i]=grid[0][i];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int cost=INT_MAX;
                for(int k=0;k<m;k++){
                    cost=min(cost,moveCost[grid[i-1][k]][j]+dp[i-1][k]+grid[i][j]);
                    // cout<<cost<<" ";
                }
                dp[i][j]=cost;
                // cout<<endl;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};