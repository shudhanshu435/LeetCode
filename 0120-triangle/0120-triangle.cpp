class Solution {
public:
    int minimumTotal(vector<vector<int>>& tt) {
        int n=tt.size();
        vector<vector<int>>dp(n,vector<int>(n));
        dp[0][0]=tt[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                // cout<<tt[i][j]<<" ";
                if(i-1>=j){
                    if(i-1>=0 and j-1>=0)dp[i][j]=tt[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                    else dp[i][j]=dp[i-1][j]+tt[i][j];
                }
                else dp[i][j]=tt[i][j] + dp[i-1][j-1];
            }
        }
        int mini=INT_MAX;
        for(auto &i:dp[n-1])mini=min(mini,i);
        return mini;
    }
};