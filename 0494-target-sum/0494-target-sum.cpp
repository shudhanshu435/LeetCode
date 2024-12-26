class Solution {
public:
    int solve(vector<int>&nums, int target, int ind, int sum, int n){
        if(ind==n)return sum==target;

        return solve(nums,target,ind+1,sum+nums[ind],n) + solve(nums,target,ind+1,sum-nums[ind],n);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(nums,target,0,0,n);
    }
};