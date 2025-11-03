class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        for(auto &i:nums)i=abs(i);
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return nums[n-1]*1ll*nums[n-2]*100000;

    }
};