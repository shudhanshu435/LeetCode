class Solution {
public:
    int maxOr = 0;
    int count = 0;

    void backtrack(const vector<int>& nums, int index, int currentOr) {
        if (index == nums.size()) { // it means you have visited all elements of array
            if (currentOr != 0) {
                if (currentOr > maxOr) {
                    maxOr = currentOr;
                    count = 1;
                } else if (currentOr == maxOr) {
                    count++;
                }
            }
            return;
        }
        // Include nums[index]
        backtrack(nums, index + 1, currentOr | nums[index]);
        // Exclude nums[index]
        backtrack(nums, index + 1, currentOr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        maxOr = 0;
        count = 0;
        backtrack(nums, 0, 0);
        return count;
    }
};