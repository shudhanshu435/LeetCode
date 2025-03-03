class Solution {
public:
    int helper(int idx, int prev, vector<int>&nums, vector<vector<int>>&dp){
        int n=nums.size();
        if(idx>=n)return 0;
        if(idx==n-1){
            if(idx%2==0){
                vector<int>v;
                v.push_back(nums[prev]);
                v.push_back(nums[idx]);
                v.push_back(nums[idx-1]);
                sort(v.begin(),v.end());
                return v[0]+v[2];
            }
            else{
                return max(nums[idx],nums[prev]);
            }
        }
        if(dp[idx][prev]!=-1)return dp[idx][prev];

        if(idx%2==0){
            vector<pair<int,int>>v;
            v.push_back({nums[idx],idx});
            v.push_back({nums[idx-1],idx-1});
            v.push_back({nums[prev],prev});
            sort(v.begin(),v.end());
            return dp[idx][prev]=min(helper(idx+1,v[0].second,nums,dp)+v[2].first, helper(idx+1,v[2].second,nums,dp)+v[1].first);
        }
        else{return dp[idx][prev]=helper(idx+1,prev,nums,dp);}
    }
    int minCost(vector<int>& nums) {
        int n=nums.size();

        if(n<=2)return *max_element(nums.begin(),nums.end());

        vector<vector<int>>dp(n,vector<int>(n,-1));

        return helper(2,0,nums,dp);
        
    }
};