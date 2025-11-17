class Solution {
public:

    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m));
        for(int i=0;i<n;i++){
            dp[i][0]=(mat[i][0]-'0');
            ans=max(ans,dp[i][0]);
        }
        for(int i=0;i<m;i++){
            dp[0][i]=(mat[0][i]-'0');
            ans=max(ans,dp[0][i]);
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]=='0')dp[i][j]=0;
                else dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                ans=max(ans,dp[i][j]*dp[i][j]);
            }
        }
        return ans;
        
    }
};