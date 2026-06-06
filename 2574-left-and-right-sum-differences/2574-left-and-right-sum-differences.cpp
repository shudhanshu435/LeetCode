class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int s=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        vector<int>vec(n);
        int curr=0;
        vec[0]=s-nums[0];
        for(int i=0;i<n-1;i++){
            curr+=nums[i];
            vec[i+1]=abs(curr-(s-curr-nums[i+1]));
        }
        return vec;
    }
};