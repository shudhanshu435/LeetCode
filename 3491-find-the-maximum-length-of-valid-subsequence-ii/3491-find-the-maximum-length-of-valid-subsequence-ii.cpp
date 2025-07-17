class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0)); // dp[prev_rem][curr_rem]
        int maxLength = 0;
        for (int num : nums) 
        {
            int current_rem = num % k;
            for (int prev_rem = 0; prev_rem < k; ++prev_rem) 
            {
                dp[prev_rem][current_rem] = dp[current_rem][prev_rem] + 1;
                maxLength = max(maxLength, dp[prev_rem][current_rem]);
            }
        }
        return maxLength;
    }
};