class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int cnt=0,cnt1=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i])cnt++;
            else if(nums[i-1]<nums[i])cnt1++;
        }
        if(cnt!=0 && cnt1!=0)return 0;
        else return 1;
    }
};