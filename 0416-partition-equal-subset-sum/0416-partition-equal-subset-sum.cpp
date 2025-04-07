class Solution {
public: 
    bool pos(vector<int>&nums, int ind, int sum, int curr){
        if(curr==sum)return 1;
        if(ind==nums.size())return 1;
        curr+=nums[ind];
        return pos(nums,ind+1,sum,curr);
        curr-=nums[ind];
        return pos(nums,ind+1,sum,curr);
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return 0;
        sum/=2;
        return pos(nums,0,sum,0);
    }
};