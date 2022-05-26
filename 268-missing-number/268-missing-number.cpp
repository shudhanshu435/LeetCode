class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int m=nums.size();
        int i=0,sum=0;
        for(;i<m;i++)sum+=nums[i];
        m=m*(m+1)/2;
        return m-sum;
    }
};