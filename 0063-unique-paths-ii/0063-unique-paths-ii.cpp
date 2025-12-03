class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int n=obs.size();
        int m=obs[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        bool b=0;
        for(int i=0;i<n;i++){
            if(obs[i][0]==1)b=1;
            if(b)dp[i][0]=0;
            else dp[i][0]=1;
        }
        b=0;
        for(int i=0;i<m;i++){
            if(obs[0][i]==1)b=1;
            if(b)dp[0][i]=0;
            else dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obs[i][j]==0)dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};