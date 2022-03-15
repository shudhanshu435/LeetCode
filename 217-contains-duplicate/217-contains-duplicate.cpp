class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){cnt++;break;}
        }
        if(cnt!=0)return 1;
        else return 0;
    }
};