class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        int n=nums.size();
        if(nums[n-1]<0)return nums[n-1];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=0 and nums[i]!=nums[i-1]){
                sum+=nums[i];
            }
        }
        if(nums[0]>0)sum+=nums[0];
        return sum;
    }
};