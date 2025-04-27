class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]/2.0==(nums[i-1]+nums[i+1]))cnt++;
        }
        return cnt;
    }
};