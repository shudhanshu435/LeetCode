class Solution {
public: 
    bool pos(vector<int>&nums, int ind, int sum, int curr, vector<vector<int>>& dp){
        if(curr==sum)return 1;
        if(ind==nums.size())return 0;
        if(dp[ind][curr]!=-1)return dp[ind][curr];
        bool take= pos(nums,ind+1,sum,curr+nums[ind],dp);
        bool nottake= pos(nums,ind+1,sum,curr,dp);

        return dp[ind][curr]=take or nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
        if(sum&1)return 0;
        sum/=2;
        return pos(nums,0,sum,0,dp);
    }
};