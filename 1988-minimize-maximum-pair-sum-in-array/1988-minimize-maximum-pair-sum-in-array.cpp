class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int i=nums.size()/2-1,j=nums.size()/2;
        while(i>=0){
            ans=max(ans,nums[i]+nums[j]);
            i--;j++;
        }
        return ans;
    }
};