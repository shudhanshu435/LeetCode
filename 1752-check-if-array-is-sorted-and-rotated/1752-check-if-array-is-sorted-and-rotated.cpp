class Solution {
public:
    bool check(vector<int>& nums) {
        int i=0;
        for(;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])break;
        }
        if(i==nums.size()-1)return 1;
        int k=i+1;
        for(;k<nums.size()-1;k++){
            if(nums[k]<=nums[k+1])continue;
            return 0;
        }
        k=nums[nums.size()-1];
        if(k<=nums[0])return 1;
        return 0;
    }
};