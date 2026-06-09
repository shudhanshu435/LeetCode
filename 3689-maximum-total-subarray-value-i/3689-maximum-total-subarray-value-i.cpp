class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return (nums[n-1]-nums[0])*1ll*k;
    }
};