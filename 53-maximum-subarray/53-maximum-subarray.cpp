class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=0,curr=0,neg=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)neg++;
            curr=curr+nums[i];
            if(curr>max)max=curr;
            if(curr<0)curr=0;
        }
        if(neg==nums.size()){
            sort(nums.begin(),nums.end());
            return nums[nums.size()-1];
        }
        return max;
    }
};