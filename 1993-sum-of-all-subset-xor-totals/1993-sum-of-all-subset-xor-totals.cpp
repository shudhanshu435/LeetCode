class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int orr=nums[0];
        for(int i=1;i<n;i++){
            orr=orr|nums[i];
        }
        orr<<=(n-1);
        return orr;
    }
};