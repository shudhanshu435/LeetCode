class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=1;i<n;i++)ans=ans|nums[i];
        ans<<=(n-1);
        return ans;
    }
};