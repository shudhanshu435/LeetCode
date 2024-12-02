class Solution {
public:
    
    int subsetXORSum(vector<int>& nums) {
        int totalXorSum = 0;
        int n = nums.size();
        
        int totalSubsets = 1 << n;

        for (int i = 0; i < totalSubsets; ++i) {
            int currentXor = 0;

            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    currentXor ^= nums[j];
                }
            }
            totalXorSum += currentXor;
        }

        return totalXorSum;
    }
};