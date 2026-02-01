class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int f=nums[0];
        sort(nums.begin(),nums.end());
        if(nums[0]==f or nums[1]==f or nums[2]==f)return nums[0]+nums[1]+nums[2];
        return f+nums[0]+nums[1];
    }
};