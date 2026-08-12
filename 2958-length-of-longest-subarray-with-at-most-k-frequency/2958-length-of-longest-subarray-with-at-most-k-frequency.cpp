class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        int left = 0;
        int res = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Add the current element to the window
            freq[nums[right]]++;

            // Shrink the window if the frequency constraint is violated
            while (freq[nums[right]] > k) {

                freq[nums[left]]--;

                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }

                left++;
            }

            // Update the maximum valid window length
            res = max(res, right - left + 1);
        }

        return res;
    }
};