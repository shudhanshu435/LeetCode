class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        for(auto i:nums)v.push_back(nums[i]);
        return v;
    }
};