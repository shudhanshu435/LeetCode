class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        vector<int>dp(16384,-1);
        dp[0]=0;

        for(int n:nums){
            vector<int>dpp=dp;
            for(int i=0;i<16284;i++){
                if(dp[i]!=-1){
                    int xox=i^n;
                    dpp[xox]=max(dpp[xox],dp[i]+1);
                }
            }
            dp=dpp;
        }

        if(target>16384 or dp[target]==-1)return -1;
        return nums.size()-dp[target];
    }
};