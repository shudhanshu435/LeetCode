class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(),0);
        n++;
        vector<int>dp(n,0);
        if(n==1)return costs[0];
        dp[n-2]=costs[n-1]+1;
        if(n==2)return dp[n-2];
        dp[n-3]=min(dp[n-2]+costs[n-2]+1,costs[n-1]+4);
        if(n==3)return dp[n-3];
        for(int i=n-4;i>=0;i--){
            dp[i]=min({dp[i+1]+costs[i+1]+1, dp[i+2]+costs[i+2]+4, dp[i+3]+costs[i+3]+9});
        }
        return dp[0];
    }
};