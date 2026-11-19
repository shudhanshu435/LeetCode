class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return min({nums[n-1]-nums[2],nums[n-3]-nums[0],nums[n-2]-nums[1]});
    }
};

// 1 4 5 7 8
// 1 3 4
// 9 27 33 58 81
// 8 28 42 58 75