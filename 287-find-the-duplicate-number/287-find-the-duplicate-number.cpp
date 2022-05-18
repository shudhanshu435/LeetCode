class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1]){
                t=nums[i];
                break;
        }
        }
            return t;
    }
};